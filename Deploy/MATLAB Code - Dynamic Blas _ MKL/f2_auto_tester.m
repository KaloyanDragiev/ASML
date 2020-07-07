    function f2_auto_tester %#codegen
    
    % include PLXA for timing
    if ~coder.target('MATLAB')
        coder.cinclude('<sys/time.h>');
        coder.cinclude('PLXA/PLXA.h');
    end
    
    fprintf('\n\nSuper test...\n');
    
    %% init
    data_nrow = 100;
    data_ncol = 100;
    buf_size  = 1000;

    % init A
    A = rand(buf_size)*eps;
    A(1:data_nrow, 1:data_ncol) = magic(100);

    % init b
    b = rand(buf_size, 1);
    b(1:data_nrow) = rand(data_nrow, 1);
    
    %% start timer full buffer
    t0 = coder.opaque('unsigned long', '0');
    elapsed_time_full = 0;
    elapsed_time_smart = 0;
    
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(t0));
    end
        
    % find solution x = A\b for full buffer
    x_full = matrix_divide(coder.ignoreConst(A), coder.ignoreConst(b));
    
    if coder.target('MATLAB')
        elapsed_time_full = toc*1e3;
    else
        elapsed_time_full = coder.ceval('time_diff_msec', t0);
    end

    fprintf('x_full(1): %15e\n', x_full(1));
    fprintf('elapsed_time_full: %gms\n', elapsed_time_full/1e3);

    %% start timer smart buffer
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(t0));
    end
    % find solution x = A\b for sub-buffer
    
    x_smart = matrix_divide_smart(coder.ignoreConst(A), coder.ignoreConst(b),...
        coder.ignoreConst(data_nrow), coder.ignoreConst(data_ncol));    
    
    if coder.target('MATLAB')
        elapsed_time_smart = toc*1e3;
    else
        elapsed_time_smart = coder.ceval('time_diff_msec', t0);
    end

    fprintf('x_smart(1): %15e\n', x_smart(1));
    fprintf('elapsed_time_smart: %gms\n', elapsed_time_smart/1e3);
    
    %% start timer Arithmetic Blas Calls
    if coder.target('MATLAB')
       tic;
    else
        coder.ceval('PLXAtimeinterval_start', coder.ref(t0));
    end
    % find solution Arithemtic
    result = Arithmetic(1000,1000,1000,1000);
    
    if coder.target('MATLAB')
        elapsed_time_smart = toc*1e3;
    else
        elapsed_time_smart = coder.ceval('time_diff_msec', t0);
    end

    %fprintf('result_A: %15e\n', result.A);
    fprintf('\nelapsed_time_smart Arithmetic is : %gms\n', elapsed_time_smart/1e3);
    
end