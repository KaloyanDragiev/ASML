% Description : DLS_coder_compile:
%
% In          :
%
% Out         :
%
% Pre.Cond    : -
%
% Post.Cond   : -
%
%
% Note        : % $LastChangedDate: 2019-03-21 17:37:11 +0100 (Thu, 21 Mar 2019) $
%               % $Author: adanilin $
%               % $Revision: 15585 $
%------------------------------------------------------------------------------%
%
%                        MATLAB Module
%
%------------------------------------------------------------------------------%
%
% Author       : Alexander Danilin
%
% History
%  23-10-2015 Creation
%  11-07-2017 PRGU: Changed name from coder_compile to DLS_coder_compile.
%
%
%------------------------------------------------------------------------------%
%
%       Copyright (c) 2015, ASML Holding N.V. (including affiliates).
%                           All rights reserved
%
%------------------------------------------------------------------------------%

%% Define types


%%  Run code generating
%   First generate 'code only' and then use main.c from examples

dest = 'dll';%'exe dll mex lib
f1_cfg = f1_get_cfg;
use_lapack = f1_cfg.use_lapack;
use_blas = f1_cfg.use_blas;

lapack_suf = '';
blas_suf = '';

fprintf('Compiling the %s code...\n', dest);

    cfg = coder.config(dest);
    %cfg.TargetLang      = 'C++';
    cfg.TargetLang      = 'C';
    cfg.EnableOpenMP    = true; 
    if strcmp(dest, 'exe')
        cfg.CustomSource    = 'main.c';
        cfg.CustomInclude   = 'codegen/src/f1';
        cfg.GenCodeOnly     = false;
    else
        cfg.GenCodeOnly     = true;
    end
    cfg.GenerateReport  = true;

    cfg.EnableVariableSizing    = true;
    cfg.MATLABSourceComments    = false;
    
    if use_lapack
        cfg.CustomLAPACKCallback = ['f1_useMyLAPACK_' f1_cfg.target_platform];
        lapack_suf = '_lapack';
    end
    
    if use_blas
        cfg.CustomBLASCallback = ['f1_useMyBLAS_' f1_cfg.target_platform];
        blas_suf = '_blas';
    end
        
if strcmp(f1_cfg.target_platform, 'linux')
    cfg.HardwareImplementation.TargetHWDeviceType = 'Intel->x86-64';
    cfg.HardwareImplementation.ProdHWDeviceType = 'Intel->x86-64';
else
    cfg.HardwareImplementation.TargetHWDeviceType = 'Intel->x86-64 (Windows64)';
    cfg.HardwareImplementation.ProdHWDeviceType = 'Intel->x86-64 (Windows64)';
end

%  cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
  cfg.DynamicMemoryAllocationThreshold = 0;
% cfg.CodeReplacementLibrary = 'Intel SSE (Linux)';
 
%  codegen -config cfg f2_auto_tester -report -o f2_auto_tester 
codegen -config cfg Tester -report -o Tester 

% makefile and export
source_folder = 'f2_auto_tester';
export_path = [f1_cfg.external_path source_folder, '\'];
if ~exist(export_path, 'dir'), mkdir(export_path); end
if strcmp(f1_cfg.target_platform, 'linux')
    source_path = sprintf('codegen\\%s\\%s\\', dest, source_folder);
    %f1_makefile('qpAS_coder_test', source_path);
    %f1_export_generated_files(source_path, export_path);
end
