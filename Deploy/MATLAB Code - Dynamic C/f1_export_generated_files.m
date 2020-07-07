function f1_export_generated_files(codegen_path, export_path)

    if nargin < 1, codegen_path = 'codegen\dll\f2_auto_tester\'; end
    if nargin < 2, export_path = '\\asml.com\eu\sdev\sdev_shared\fc063data\DLS\student_mode\'; end

    f1_cfg = f1_get_cfg;
    
    fprintf('Cleaning up export folder %s...\n', export_path);
    delete([export_path, '*.*']);
    
    fprintf('Exporting generated files to %s...\n', export_path);
    system(sprintf('copy %s*.c %s*.c', codegen_path, export_path));
    system(sprintf('copy %s*.h %s*.h', codegen_path, export_path));
    system(sprintf('copy makefile %smakefile', export_path));
    
    fprintf('Exporting main files to %s...\n', export_path);
    system(sprintf('copy %s*.* %s*.*', f1_cfg.main_include, export_path));
    
    if f1_cfg.use_timing
        fprintf('Exporting timing files to %s...\n', export_path);
        system(sprintf('copy %s*.c %s*.c', '.\', export_path));
        system(sprintf('copy %s*.h %s*.h', '.\', export_path));
    end

    if f1_cfg.use_lapack
        fprintf('Exporting LAPACK files to %s...\n', export_path);
        system(sprintf('copy %s*.h %s.*h', f1_cfg.lapack_include, export_path));
    end

    if f1_cfg.use_blas
        fprintf('Exporting BLAS files to %s...\n', export_path);
        system(sprintf('copy %s*.h %s*.h', f1_cfg.blas_include, export_path));
    end
    
end