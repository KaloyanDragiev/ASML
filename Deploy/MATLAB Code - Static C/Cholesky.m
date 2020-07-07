function L = Cholesky(A, data_nrow, data_ncol)
    coder.inline('never');

    if coder.target('MATLAB')
        L = chol(A(1:data_nrow,1:data_ncol), 'lower');
    else  
        L = chol(A(1:data_nrow,1:data_ncol), 'lower');
        
%         coder.cinclude('cblas.h')
%     
%         CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor');
%         CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft');
%         CblasUpper = coder.opaque('CBLAS_UPLO', 'CblasUpper');
%         CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');
%         CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit');         
    end
end
% scaling_Factor_A_X = -1.0.
% scaling_Factor_Y = 1.0;
% cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(99 - j), (int)j, scaling_Factor_A_X,
%                       &A[j + 1], (int)100, &A[j], (int)100, scaling_Factor_Y, &A[jj + 1],
%                       (int)1);