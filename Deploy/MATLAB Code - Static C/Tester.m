function Tester%#codegen
%% Initialize Values

data_nrow = 100; % Change range size
data_ncol = 100; % Change range size
timesToRun = 10; % Change number of times the calcuations are performed 

time = coder.opaque('unsigned long', '0');
elapsed_time = 0;

%Calculate elapse time start 256
if coder.target('MATLAB')
   tic;
else
    coder.ceval('PLXAtimeinterval_start', coder.ref(time));
end

buf_size  = 256; 
f3_auto_tester(data_nrow, data_ncol, buf_size, timesToRun);

%Calculate elapse time end 256
if coder.target('MATLAB')
    elapsed_time = toc * 1e3;
else
    elapsed_time = coder.ceval('time_diff_msec', time);
end

fprintf('\nTime for f3_auto_tester with size 256: %gms\n', elapsed_time/1e3); 


%Calculate elapse time start 512
if coder.target('MATLAB')
   tic;
else
    coder.ceval('PLXAtimeinterval_start', coder.ref(time));
end

buf_size  = 512;  
f3_auto_tester(data_nrow, data_ncol, buf_size, timesToRun);

%Calculate elapse time end 512
if coder.target('MATLAB')
    elapsed_time = toc * 1e3;
else
    elapsed_time = coder.ceval('time_diff_msec', time);
end

fprintf('\nTime for f3_auto_tester with size 512: %gms\n', elapsed_time/1e3); 


%Calculate elapse time start 1024
if coder.target('MATLAB')
   tic;
else
    coder.ceval('PLXAtimeinterval_start', coder.ref(time));
end

buf_size  = 1024;
f3_auto_tester(data_nrow, data_ncol, buf_size, timesToRun);

%Calculate elapse time end 1024
if coder.target('MATLAB')
    elapsed_time = toc * 1e3;
else
    elapsed_time = coder.ceval('time_diff_msec', time);
end

fprintf('\nTime for f3_auto_tester with size 1024: %gms\n', elapsed_time/1e3); 


%Calculate elapse time start 2048
if coder.target('MATLAB')
   tic;
else
    coder.ceval('PLXAtimeinterval_start', coder.ref(time));
end

buf_size  = 2048; 
f3_auto_tester(data_nrow, data_ncol, buf_size, timesToRun);

%Calculate elapse time end 2048
if coder.target('MATLAB')
    elapsed_time = toc * 1e3;
else
    elapsed_time = coder.ceval('time_diff_msec', time);
end

fprintf('\nTime for f3_auto_tester with size 2048: %gms\n', elapsed_time/1e3); 


%Calculate elapse time start 4096
if coder.target('MATLAB')
   tic;
else
    coder.ceval('PLXAtimeinterval_start', coder.ref(time));
end

buf_size  = 4096; 
f3_auto_tester(data_nrow, data_ncol, buf_size, timesToRun);

%Calculate elapse time end 4096
if coder.target('MATLAB')
    elapsed_time = toc * 1e3;
else
    elapsed_time = coder.ceval('time_diff_msec', time);
end

fprintf('\nTime for f3_auto_tester with size 4096: %gms\n', elapsed_time/1e3); 
end