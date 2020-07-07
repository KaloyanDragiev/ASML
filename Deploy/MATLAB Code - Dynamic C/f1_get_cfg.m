function f1_cfg = f1_get_cfg

    f1_cfg.target_platform = 'linux';
    f1_cfg.target_release = 'R63'; % can be 'R63' or 'QBL'
    f1_cfg.use_timing = true;
    f1_cfg.report_differences = false;
    f1_cfg.report_per_exposure = false;

    f1_cfg.use_blas = 0;
    f1_cfg.blas_include = 'lapack-3.8.0\CBLAS\include\';

    f1_cfg.use_lapack = 0;
    f1_cfg.lapack_include = 'lapack-3.8.0\LAPACKE\include\';
    
    f1_cfg.main_include = 'codegen\src\';

    if coder.target('MATLAB')
        f1_cfg.accuracy = 1e-12;
    else
        f1_cfg.accuracy = 1e-10;
    end
    
    f1_cfg.number_of_runs_per_case = 1;
    
    f1_cfg.fn_test_vectors = 'KILMEX/tstpkg/test_vectors.bin';
    f1_cfg.fn_TC_list = 'KILMEX/tstpkg/F1_TC_list.csv';

    %f1_cfg.external_path = '\\asml.com\eu\shared\nl011066\ImageMetrology\2050\users\ADAP\qpAS_coder\';
    f1_cfg.external_path = '\\asml.com\eu\sdev\sdev_shared\fc063data\DLS\solver_test_framework\';

    
end