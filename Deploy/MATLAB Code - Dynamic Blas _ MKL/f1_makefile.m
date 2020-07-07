function f1_makefile(target, folder_name, template_file_name, replace_key, output_makefile_name)

    if nargin < 1, target = 'qpAS_coder_test'; end
    if nargin < 2, folder_name = 'codegen\dll\f2_auto_tester\'; end
    if nargin < 3, template_file_name = 'makefile_template'; end
    if nargin < 4, replace_key = '#%{TPL1}%#'; end
    if nargin < 5, output_makefile_name = 'makefile'; end
    
    fprintf('Generating makefile...\n');

    % add mail solver files generated by coder
    d = dir([folder_name, '*.c']);
    make_string = sprintf('X86TARGET += %s\n%s,SRCS = main.c \\\n   ', target, target);
    for n=1:length(d)
        make_string = sprintf('%s%s \\\n   ', make_string, d(n).name);
    end
    
    % add local c files
    f1_cfg = f1_get_cfg;
    if f1_cfg.use_timing
        d = dir('*.c');
        for n=1:length(d)
            make_string = sprintf('%s%s \\\n   ', make_string, d(n).name);
        end
    end
    
    % append library section
    make_string = sprintf('%s\n%s,USRLIBS = \\',   make_string, target);
    make_string = sprintf('%s\n   libKILMEX_qpAS_mkl \\',   make_string);
    make_string = sprintf('%s\n   libPLXA \\',   make_string);
    %make_string = sprintf('%s\n   libmtsk \\',   make_string);
    %make_string = sprintf('%s\n   libmkl_core \\',   make_string);
    %make_string = sprintf('%s\n   libmkl_sequential \\',   make_string);
    make_string = sprintf('%s\n   libmkl_rt \\',   make_string);
         
    % replace KEY with generated list
    tpl = EUGS_file_read([template_file_name '_' f1_cfg.target_release]);
    tpl = strrep(tpl', replace_key, make_string);
    EUGS_file_write(output_makefile_name, tpl);
    
end