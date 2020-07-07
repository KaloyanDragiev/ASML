% small check
fn1 = 'f3_mat_y.bin';
fn2 = 'f3_lin_y_Dev.bin';

x_result_mat = f3_array_load_bin(fn1);
x_result_lin = f3_array_load_bin(fn2);

figure;plot(x_result_mat - x_result_lin, '*');
result = sum(x_result_mat - x_result_lin)

%         assert(isequal(x_result_check, x_result_check2));
%         figure;plot(x_result_check - x_result_check2);
