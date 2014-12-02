function xValidateAnalysis = trainManyNN(pathSgn,pathBkg,inputopts)
%
% TODO Help
%

% - Creation Date: Fri, 26 Sep 2014
% - Last Modified: Sat, 27 Sep 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

	defopts = struct(
		'trainWrt','truth','useFastNet',1,...
		'truth_type',11,'truth_mothertype',23,...
		'trnSgnIsEM_mask',966493,'trnBkgIsEM_mask',93,...
    'debug',false);

	if(~exist('inputopts','var')) 
		inputopts = struct; 
	end

	opts = scanparam(defopts,inputopts);

  if ischar(pathSgn)
    load(pathSgn);
  else isstruct(pathSgn)
    elc = pathSgn;
  end

  if ischar(pathBkg)
    load(pathBkg);
  else
    jet = pathBkg;
  end

	if(strcmp(opts.trainWrt,'truth'))
    sgn = elc.el_rings_E(:, ...
      abs(elc.el_truth_type) == opts.truth_type & ...
      elc.el_truth_mothertype == opts.truth_mothertype);
    bkg = jet.el_rings_E;
	elseif(strcmp(opts.trainWrt,'standard'))
    sgn = elc.el_rings_E(:,~(bitand(elc.el_isEM,...
      opts.trnSgnIsEM_mask)));
    bkg = jet.el_rings_E(:,bitand(jet.el_isEM,...
      opts.trnBkgIsEM_mask));
	else
		Output.ERROR(...
		  'Allowed trainWrt arguments are: truth or standard.');
	end

	clear elc jet

  xValidateAnalysis = xValidateBinaryClassifier(sgn,bkg,inputopts);

end

