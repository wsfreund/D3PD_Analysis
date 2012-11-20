function opts = scanparam(defoptions,options)
% Copyright 2008 by A.H. Phan and A. Cichocki
allfields = fieldnames(defoptions); 
opts = defoptions;
for k = 1:numel(allfields) 
  if isfield(options,allfields{k})
		opts.(allfields{k}) = options.(allfields{k});
  end
end
