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
    %nonFlipedNorm0 = matchedFilterStruct.matchS0'*inData/matchedFilterStruct.normS0^2
    %nonFlipedNorm1 = matchedFilterStruct.matchS1'*inData/matchedFilterStruct.normS1^2
    %nonFlipedData0 = bsxfun(@rdivide,matchedFilterStruct.matchS0'*inData,sum(inData.^2))
    %nonFlipedData1 = bsxfun(@rdivide,matchedFilterStruct.matchS1'*inData,sum(inData.^2))
    %flipedNorm0 = flipud(matchedFilterStruct.matchS0)'*inData/matchedFilterStruct.normS0^2
    %flipedNorm1 = flipud(matchedFilterStruct.matchS1)'*inData/matchedFilterStruct.normS1^2
    %flipedData0 = bsxfun(@rdivide,flipud(matchedFilterStruct.matchS0)'*inData,sum(inData.^2))
    %flipedData1 = bsxfun(@rdivide,flipud(matchedFilterStruct.matchS1)'*inData,sum(inData.^2))
    %nonFlipedNorm0Data = bsxfun(@rdivide,matchedFilterStruct.matchS0'*inData/matchedFilterStruct.normS0,sum(inData.^2).^(1/2))
    %nonFlipedNorm1Data = bsxfun(@rdivide,matchedFilterStruct.matchS1'*inData/matchedFilterStruct.normS1,sum(inData.^2).^(1/2))
    %flipedNorm0Data = bsxfun(@rdivide,flipud(matchedFilterStruct.matchS0)'*inData/matchedFilterStruct.normS0,sum(inData.^2).^(1/2))
    %flipedNorm1Data = bsxfun(@rdivide,flipud(matchedFilterStruct.matchS1)'*inData/matchedFilterStruct.normS1,sum(inData.^2).^(1/2))

    %nonFlipedNorm = ...
    %  matchedFilterStruct.matchS0'*inData/...
    %    matchedFilterStruct.normS0^2 - ...
    %  matchedFilterStruct.matchS1'*inData/...
    %    matchedFilterStruct.normS1^2
    %flipedNorm = ...
    %  flipud(matchedFilterStruct.matchS0)'*inData/...
    %    matchedFilterStruct.normS0^2 - ...
    %  flipud(matchedFilterStruct.matchS1)'*inData/...
    %    matchedFilterStruct.normS1^2
    %filterAns = ...
    %  flipud(matchedFilterStruct.matchS0)'*inData/...
    %    matchedFilterStruct.normS0^2 - ...
    %  flipud(matchedFilterStruct.matchS1)'*inData/...
    %    matchedFilterStruct.normS1^2;
    % Normalize inData to unit norm:
    inData = bsxfun(@rdivide,inData,sum(inData.^2,1).^(1/2));
    %nonFlipedData = ...
    %  matchedFilterStruct.matchS0'*inData - ...
    %  matchedFilterStruct.matchS1'*inData
    filterAns = ...
      matchedFilterStruct.matchS0'*inData - ...
      matchedFilterStruct.matchS1'*inData;

    %nonFlipedNormData = nonFlipedNorm0Data - nonFlipedNorm1Data;
    %flipedNormData = flipedNorm0Data - flipedNorm1Data;

    %meanNonFlipedNorm = mean(nonFlipedNorm)
    %meanFlipedNorm = mean(flipedNorm)
    %meanNonFlipedData = mean(nonFlipedData)
    %meanFlipedData = mean(flipedData)
    %meanNonFlipedNormData = mean(nonFlipedNormData)
    %meanFlipedNormData = mean(flipedNormData)
      
  case 'stochastic'
    % Id : for Id we work on sample with the mean, since this is the
    % deterministic information we are training to match:

    % Ir : for Ir we work on the sample without the mean, since we
    % removed it for the pca calculation:
  end
end




