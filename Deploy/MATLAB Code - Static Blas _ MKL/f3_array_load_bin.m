function data = f3_array_load_bin(fn)

if nargin < 1, fn = 'f3.bin'; end

data = 0;
f = fopen(fn, 'r');
if f < 0, data = 1; return; end

data = fread(f, 'double');
fclose(f);

end