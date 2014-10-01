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

  if strcmp(opts.implementation,'stochastic')
    %Ir0 = 
  end

  %inData = bsxfun(@rdivide,inData,sum(inData.^2,1).^(1/2));

  % Id : for Id we work on sample with the mean (or the most
  % correlated sample), since this is the deterministic information we
  % are trying to match:
  Id = ...
    matchedFilterStruct.matchS0'*inData - ...
    matchedFilterStruct.matchS1'*inData;

  switch opts.implementation
  case 'deterministic'
    filterAns = Id;
  case 'stochastic'
    N0 = matchedFilterStruct.opts.N0;
    % Ir : for Ir we work on the sample without the mean, since we
    % removed it for the pca calculation:
    Ir = ...
      ... % Ir0:
      bsxfun(@times,... % This multiplication is the scale factor
        matchedFilterStruct.phi0(1:matchedFilterStruct.nCompH0d,:)* ... % Project data
        bsxfun(@minus,inData,matchedFilterStruct.dataMean0).^2.* ... % Take square from the projected data
        ,(matchedFilterStruct.lambda0square./...    % And here is the scale factor
        (matchedFilterStruct.lambda0square+N0/2)) ...
      - ... % Ir1:
      bsxfun(@times,... % This multiplication is the scale factor
        matchedFilterStruct.phi1(1:matchedFilterStruct.nCompH1d,:)* ... % Project data
        bsxfun(@minus,inData,matchedFilterStruct.dataMean1).^2.* ... % Take square from the projected data
        ,(matchedFilterStruct.lambda1square./...    % And here is the scale factor
        (matchedFilterStruct.lambda1square+N1/2));
    % Filter answer is the sum from the deterministic component and 
    filterAns = Ir + Id; 
  end
end




