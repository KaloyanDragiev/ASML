function [x, A, B] = multiply_Smart(A, B, data_nrow, data_ncol)
    coder.inline('never');
    x = ones(data_nrow, 1);

%      if coder.target('MATLAB')
          x = A(1:data_nrow,1:data_ncol) * B(1:data_ncol);
%     else    
%         coder.cinclude('cblas.h')
%         
%         scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B.
%         scaling_Factor_C = 0.0; % Scaling factor for matrix C.
%         n_col_B_C = 1; % Number of columns in matrices B and C.
%         
%         CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor');
%         CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');  
%         CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');  
%         
%         coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ...
%             scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow);
%     end    
end

%        cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int)
%     90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90