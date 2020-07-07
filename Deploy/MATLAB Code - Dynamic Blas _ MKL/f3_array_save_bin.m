function err = f3_array_save_bin(fn, data)

if nargin < 1, fn = 'f3.bin'; end
if nargin < 2, data = []; end

err = 0;
f = fopen(fn, 'w');
if f < 0, err = 1; return; end

fwrite(f, data(:), 'double');
fclose(f);

end