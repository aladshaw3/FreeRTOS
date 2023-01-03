model = 'test';
open_system(model);
out = sim(model);
assert( out.ErrorMessage == "")
close_system(model);
