classdef f1_useMyBLAS_linux < coder.BLASCallback
    methods (Static)
        function updateBuildInfo(buildInfo, ~)
            libPath = fullfile(pwd,'mkl','WIN','lib','intel64');
            libPriority = '';
            libPreCompiled = true;
            libLinkOnly = true;
            libs = {'mkl_intel_ilp64.lib' 'mkl_intel_thread.lib' 'mkl_core.lib'};
            buildInfo.addLinkObjects(libs, libPath, libPriority, libPreCompiled, libLinkOnly);
            buildInfo.addLinkObjects('libiomp5md.lib',fullfile(matlabroot,'bin','win64'), ...
                libPriority, libPreCompiled, libLinkOnly);
            buildInfo.addIncludePaths(fullfile(pwd,'mkl','WIN','include'));
            buildInfo.addDefines('-DMKL_ILP64');
        end
        function headerName = getHeaderFilename()
            headerName = 'cblas.h';
        end
        function intTypeName = getBLASIntTypeName()
            intTypeName = 'int';
        end
    end
end