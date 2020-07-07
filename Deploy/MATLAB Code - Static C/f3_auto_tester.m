function f3_auto_tester(data_nrow, data_ncol, buf_size, timesToRun) %#codegen
%% Initialize 

A = randi(buf_size, buf_size);
A = A'*A;
B = A(1:buf_size, 1);

AverageTimeLinSolve = zeros(1, timesToRun);
AverageTimeCholesky = zeros(1, timesToRun);
AverageTimeSVD = zeros(1, timesToRun);
AverageTimeMultiplyNormal = zeros(1, timesToRun);
AverageTimeMultiplySmart = zeros(1, timesToRun);
%% LinSolve, Cholesky,  SVD, Multiplication Normal, Smart
 
%Calculate Cholesky for LinSolve
L = Cholesky(A, data_nrow, data_ncol);   
U = L';

%Run the calculations X times for correcteness 
for n = 1:timesToRun
    
    % opts settings
    opts.LT = false;
    opts.UT = false;
    opts.TRANSA = false;

    %Calculate elapse time LinSolve start
    time = coder.opaque('unsigned long', '0');
    elapsed_time_linsolve = 0;
    elapsed_time_cholesky = 0;
    elapsed_time_svd = 0;
    elapsed_time_multiplyNormal = 0;
    elapsed_time_multiplySmart = 0;

    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(time));
    end

    %Forward
    opts.LT = true;
    opts.TRANSA = false;    
    
    [y_result] = linsolve_blas(L, B, data_nrow, data_ncol, opts);

    %Backward
    opts.LT = false;
    opts.UT = true;
    opts.TRANSA = false;  
     
    [x_result] = linsolve_blas(U, y_result, data_nrow, data_ncol, opts);

    %Calculate elapse time LinSolve end
    if coder.target('MATLAB')
        elapsed_time_linsolve = toc * 1e3;
    else
        elapsed_time_linsolve = coder.ceval('time_diff_msec', time);
    end
 
%Calculate Cholesky  

    %Calculate elapse time Cholesky start
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(time));
    end
        
    cholesky = chol(A(1:buf_size,1:buf_size), 'lower');
    
    %Calculate elapse time Cholesky end
    if coder.target('MATLAB')
        elapsed_time_cholesky = toc * 1e3;
    else
        elapsed_time_cholesky = coder.ceval('time_diff_msec', time);
    end
           
%Calculate SVD  

    %Calculate elapse time SVD start
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(time));
    end
    
    [u,S,V] = SVD(A, buf_size, buf_size);
    
    %Calculate elapse time SVD end
    if coder.target('MATLAB')
        elapsed_time_svd = toc * 1e3;
    else
        elapsed_time_svd = coder.ceval('time_diff_msec', time);
    end

%Calculate Multiplication Normal

    %Calculate elapse time Multiplication Normal start
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(time));
    end

    [normal, A, B] = multiply_Smart(A, B, buf_size, buf_size); 

    %Calculate elapse time Multiplication Normal end
    if coder.target('MATLAB')
        elapsed_time_multiplyNormal = toc * 1e3;
    else
        elapsed_time_multiplyNormal = coder.ceval('time_diff_msec', time);
    end
        
%Calculate Multiplication Smart

    %Calculate elapse time Multiplication Smart start
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(time));
    end

    [x, A, B] = multiply_Smart(A, B, data_nrow, data_ncol);

    %Calculate elapse time Multiplication Smart end
    if coder.target('MATLAB')
        elapsed_time_multiplySmart = toc * 1e3;
    else
        elapsed_time_multiplySmart = coder.ceval('time_diff_msec', time);
    end
    
%Save/Check Results and Precision 
    if coder.target('MATLAB')
        fn = 'f3_mat_x.bin';
        err = f3_array_save_bin(fn, x_result);

        fn2 = 'f3_mat_y.bin';
        err2 = f3_array_save_bin(fn2, y_result);
        
        fn3 = 'f3_chol.bin'; 
        err3 = f3_array_save_bin(fn3, cholesky); 
        
        fn4 = 'f3_svd.bin'; 
        err4 = f3_array_save_bin(fn4, u);
        
        fn5 = 'f3_multiplyNorm.bin'; 
        err5 = f3_array_save_bin(fn5, normal);  
        
        fn6 = 'f3_multiplySmart.bin'; 
        err6 = f3_array_save_bin(fn6, x); 
    else
        fn = 'f3_lin_x.bin'; 
        err = f3_array_save_bin(fn, x_result);

        fn2 = 'f3_lin_y.bin'; 
        err2 = f3_array_save_bin(fn2, y_result);   
        
        fn3 = 'f3_chol.bin'; 
        err3 = f3_array_save_bin(fn3, cholesky); 
        
        fn4 = 'f3_svd.bin'; 
        err4 = f3_array_save_bin(fn4, u);
        
        fn5 = 'f3_multiplyNorm.bin'; 
        err5 = f3_array_save_bin(fn5, normal);  
        
        fn6 = 'f3_multiplySmart.bin'; 
        err6 = f3_array_save_bin(fn6, x);   
    end     
    
    AverageTimeLinSolve(n) = elapsed_time_linsolve;
    AverageTimeCholesky(n) = elapsed_time_cholesky;
    AverageTimeSVD(n) = elapsed_time_svd;
    AverageTimeMultiplyNormal(n) = elapsed_time_multiplyNormal;
    AverageTimeMultiplySmart(n) = elapsed_time_multiplySmart;
end

fprintf('\n---------------------------------------------------------------\n');
fprintf('For matrix size: %3e\n', buf_size); 
fprintf('\nSame values - set range of calcuations 100x100 (LinSolve & Smart Multiply): \n\n');
fprintf('Worst Time LinSolve: %gms\n', max(AverageTimeLinSolve)/1e3); 
fprintf('Average Time LinSolve: %gms\n', mean(AverageTimeLinSolve)/1e3); 
fprintf('Best Time LinSolve: %gms\n\n', min(AverageTimeLinSolve)/1e3); 

fprintf('Worst Time Multiply Smart: %gms\n', max(AverageTimeMultiplySmart)/1e3); 
fprintf('Average Time Multiply Smart: %gms\n', mean(AverageTimeMultiplySmart)/1e3);
fprintf('Best Time Multiply Smart: %gms\n', min(AverageTimeMultiplySmart)/1e3);
fprintf('\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n');

fprintf('Worst Time Cholesky: %gms\n', max(AverageTimeCholesky)/1e3); 
fprintf('Average Time Cholesky: %gms\n', mean(AverageTimeCholesky)/1e3);
fprintf('Best Time Cholesky: %gms\n\n', min(AverageTimeCholesky)/1e3);

fprintf('Worst Time SVD: %gms\n', max(AverageTimeSVD)/1e3); 
fprintf('Average Time SVD: %gms\n', mean(AverageTimeSVD)/1e3);
fprintf('Best Time SVD: %gms\n\n', min(AverageTimeSVD)/1e3);

fprintf('Worst Time Multiply Normal: %gms\n', max(AverageTimeMultiplyNormal)/1e3); 
fprintf('Average Time Multiply Normal: %gms\n', mean(AverageTimeMultiplyNormal)/1e3);
fprintf('Bes tTime Multiply Normal: %gms\n', min(AverageTimeMultiplyNormal)/1e3);

end