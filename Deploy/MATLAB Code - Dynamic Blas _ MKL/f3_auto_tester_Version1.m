function f3_auto_tester %#codegen
%% Initialize
%     coder.extrinsic('input');
%     prompt = 'Input biffer size: ';
%     buf_size = input(prompt);
%     prompt = 'Input row : ';
%     data_nrow = input(prompt);
%     prompt = 'Input col : ';
%     data_ncol = input(prompt);

data_nrow = 100;
data_ncol = 100;    
buf_size  = 10000;

A = magic(buf_size);
C = A(A <= 10000);
B = C(1:buf_size, 1);

% B = ones(size(A,2),1);
% B = randi(10,size(A,2),1);% B = A(1:buf_size, 1);

AverageTimeLinSolve = zeros(1, 50);
AverageTimeMultiplySmart = zeros(1, 50);
NumberOfMatchesX = 0;
NumberOfMatchesY = 0;
AverageAccurecyX = zeros(1, 50);
AverageAccurecyY = zeros(1, 50);

%% LinSolve

%Calculate Cholesky    
L = Cholesky(A, data_nrow, data_ncol);   
U = L';

%Run the calculations 50 times for correcteness 
for n = 1:50
    % opts settings
    opts.LT = false;
    opts.UT = false;
    opts.TRANSA = false;

    fprintf('\n\nSuper tester...\n\n');

    %Calculate elapse time LinSolve start
    time = coder.opaque('unsigned long', '0');
    elapsed_time_BLAS = 0;
    elapsed_time_multiply = 0;

    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(time));
    end

    %Forward
    opts.LT = true;
    opts.TRANSA = false;    
    for i = 1:5
        [y_result, L, B] = linsolve_blas(coder.ignoreConst(L), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ...
        coder.ignoreConst(data_ncol), coder.ignoreConst(opts));
    end
    %Backward
    opts.LT = false;
    opts.UT = true;
    opts.TRANSA = false;    
    for j = 1:5
        [x_result, U, y_result] = linsolve_blas(coder.ignoreConst(U), coder.ignoreConst(y_result), coder.ignoreConst(data_nrow), ... 
        coder.ignoreConst(data_ncol), coder.ignoreConst(opts));
    end
        
    fprintf('x_result(1): %15e\n', x_result(1));    
    fprintf('x_result(2): %15e\n', x_result(2));    
    fprintf('x_result(3): %15e\n', x_result(3));    
    fprintf('x_result(4): %15e\n', x_result(4));  
    fprintf('x_result(5): %15e\n', x_result(5));

    fprintf('\n')    
    fprintf('y_result(1): %15e\n', y_result(1));    
    fprintf('y_result(2): %15e\n', y_result(2));    
    fprintf('y_result(3): %15e\n', y_result(3));    
    fprintf('y_result(4): %15e\n', y_result(4));  
    fprintf('y_result(5): %15e\n', y_result(5));

    %Calculate elapse time LinSolve end
    if coder.target('MATLAB')
        elapsed_time_BLAS = toc * 1e3;
    else
        elapsed_time_BLAS = coder.ceval('time_diff_msec', time);
    end

    fprintf('\nElapsed_time_BLAS: %gms\n', elapsed_time_BLAS/1e3);

    %Calculate elapse time Multiplication start
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(time));
    end

    %Smart Multiplication
    [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ...
        coder.ignoreConst(data_ncol));
    fprintf('\nMultiply Smart(1): %15e\n', x(1));
    fprintf('Multiply Smart(2): %15e\n', x(2));    

    %Calculate elapse time Multiplication end
    if coder.target('MATLAB')
        elapsed_time_multiply = toc * 1e3;
    else
        elapsed_time_multiply = coder.ceval('time_diff_msec', time);
    end
    fprintf('\nElapsed_time_multiply: %gms\n', elapsed_time_multiply/1e3);
    
    %Save/Check LinSolve Results and Precision 
    if coder.target('MATLAB')
        fn = 'f3_mat_x.bin';
        err = f3_array_save_bin(fn, x_result);

        fn2 = 'f3_mat_y.bin';
        err2 = f3_array_save_bin(fn2, y_result);
    else
        x_result_MATLAB = f3_array_load_bin('f3_mat_x.bin');
        y_result_MATLAB = f3_array_load_bin('f3_mat_y.bin');

        fn = 'f3_lin_x.bin'; 
        err = f3_array_save_bin(fn, x_result);
        x_result_C = f3_array_load_bin(fn);

        fn2 = 'f3_lin_y.bin'; 
        err2 = f3_array_save_bin(fn2, y_result);
        y_result_C = f3_array_load_bin(fn2);

        %       Check x results
        if isequal(x_result_MATLAB, x_result_C) 
            fprintf('\n The Results Match!\n');
            fprintf('x_result_MATLAB(1): %15e\n', x_result_MATLAB(1)); 
            fprintf('x_result_MATLAB(2): %15e\n', x_result_MATLAB(2)); 
            fprintf('x_result_C(1): %15e\n', x_result_C(1)); 
            fprintf('x_result_C(2): %15e\n', x_result_C(2));
            NumberOfMatchesX = NumberOfMatchesX + 1;
        else         
            fprintf('\n The Results Dont Match!\n');
            fprintf('x_result_MATLAB(1): %15e\n', x_result_MATLAB(1)); 
            fprintf('x_result_MATLAB(2): %15e\n', x_result_MATLAB(2));  
            fprintf('x_result_C(1): %15e\n', x_result_C(1)); 
            fprintf('x_result_C(2): %15e\n', x_result_C(2)); 
        end
        %       Check y results
        if isequal(y_result_MATLAB, y_result_C) 
            fprintf('\n The Results Match!\n');
            fprintf('y_result_MATLAB(1): %15e\n', y_result_MATLAB(1)); 
            fprintf('y_result_MATLAB(2): %15e\n', y_result_MATLAB(2)); 
            fprintf('y_result_C(1): %15e\n', y_result_C(1)); 
            fprintf('y_result_C(2): %15e\n', y_result_C(2));
            NumberOfMatchesY = NumberOfMatchesY + 1;
        else         
            fprintf('\n The Results Dont Match!\n');
            fprintf('y_result_MATLAB(1): %15e\n', y_result_MATLAB(1)); 
            fprintf('y_result_MATLAB(2): %15e\n', y_result_MATLAB(2));  
            fprintf('y_result_C(1): %15e\n', y_result_C(1)); 
            fprintf('y_result_C(2): %15e\n', y_result_C(2)); 
        end

        %Check Precision X,Y results
        tempX = x_result_MATLAB - x_result_C;
        PrecisionX = sum(tempX);
        fprintf('\nPrecision of X results: %15e\n', PrecisionX); 
        AverageAccurecyX(n) = PrecisionX;

        tempY = y_result_MATLAB - y_result_C;
        PrecisionY = sum(tempY);
        fprintf('Precision of Y results: %15e\n', PrecisionY);  
        AverageAccurecyY(n) = PrecisionY;  
    end     
    
    AverageTimeLinSolve(n) = elapsed_time_BLAS;
    AverageTimeMultiplySmart(n) = elapsed_time_multiply;
end

fprintf('\n--------------------------------------\n');
fprintf('AverageTimeLinSolve: %gms\n', mean(AverageTimeLinSolve)/1e3); 
fprintf('AverageTimeMultiplySmart: %gms\n', mean(AverageTimeMultiplySmart)/1e3); 

fprintf('NumberOfMatchesX: %15e\n', NumberOfMatchesX); 
fprintf('NumberOfMatchesY: %15e\n', NumberOfMatchesY);

fprintf('AverageAccurecyX: %15e\n', mean(AverageAccurecyX)/1e3); 
fprintf('AverageAccurecyY: %15e\n', mean(AverageAccurecyY)/1e3); 

end