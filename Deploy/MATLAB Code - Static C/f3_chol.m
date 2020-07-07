row = 100;
col = 100;
A = magic(1000);
L = chol(A(1:row,1:col), 'lower'); % <--
U = L';
b = A(:, 1);

%forward
opts.LT = true;
opts.TRANSA = false;
y = linsolve(L(1:row,1:col), b(1:row), opts);  % <--

%backward
opts.LT = false;
opts.UT = true;
opts.TRANSA = false;
x = linsolve(U(1:row,1:col), y(1:row), opts);  % <--

fprintf('ValueX(1): %15e\n',x(1),x(2),x(3),x(4),x(5));
    fprintf('\n')    
fprintf('ValueY(1): %15e\n',y(1),y(2),y(3),y(4),y(5));


%     data_nrow = 100;
%     data_ncol = 90;