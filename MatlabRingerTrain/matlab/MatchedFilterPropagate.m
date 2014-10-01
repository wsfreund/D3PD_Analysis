function filterAns = MatchedFilterPropagate(matchedFilterStruct,...
  inData)
%
% TODO Help
%

% - Creation Date: Wed, 01 Oct 2014
% - Last Modified: Wed, 01 Oct 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  opts = matchedFilterStruct.opts;

  % Check if user requested whitening:
  if ~isempty(opts.whiteningMean)
    % Remove noise mean:
    inData = bsxfun(@minus,inData,opts.whiteningMean);
  end

  if ~isempty(opts.whiteningMatrix)
    % Remove noise mean:
    inData = opts.whiteningMatrix*inData;
  end

  switch opts.implementation
  case 'deterministic'
    inData = bsxfun(@rdivide,inData,sum(inData.^2,1).^(1/2));
    filterAns = ...
      matchedFilterStruct.matchS0'*inData - ...
      matchedFilterStruct.matchS1'*inData;
  case 'stochastic'
    % Id : for Id we work on sample with the mean, since this is the
    % deterministic information we are training to match:

    % Ir : for Ir we work on the sample without the mean, since we
    % removed it for the pca calculation:
  end
end




