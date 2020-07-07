function [result] = linsolve_blas(A, B, data_nrow, data_ncol, opts)
    coder.inline('never');
    
    %Define variables
    result = nan;
    
    if coder.target('MATLAB')     
        result = linsolve(A(1:data_nrow,1:data_ncol), B(1:data_nrow), opts); 
    else
        coder.cinclude('cblas.h')
            
        result = B(1:data_nrow,1:data_ncol); % Assign result to B - Because B gets overwritten otherwise
        n_columns_B = 1; % The number of columns in matrix B.
        scaling_Factor_A = 1.0; % Scaling factor for matrix A.
        
        if opts.LT == 1 
            CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor');
            CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft');
            CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');    
            CblasLower = coder.opaque('CBLAS_UPLO', 'CblasLower');
            CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit');

            %forward
            coder.ceval('cblas_dtrsm', CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, ...
            data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow);
        else            
            CblasColMajor1 = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor');
            CblasLeft1 = coder.opaque('CBLAS_SIDE', 'CblasLeft');
            CblasUpper1 = coder.opaque('CBLAS_UPLO', 'CblasUpper');
            CblasNoTrans1 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');
            CblasNonUnit1 = coder.opaque('CBLAS_DIAG', 'CblasNonUnit');

            %backward
            coder.ceval('cblas_dtrsm', CblasColMajor1, CblasLeft1, CblasUpper1, CblasNoTrans1, CblasNonUnit1, ...
            data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow);
        end        
    end
end

%   cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
%               (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90;