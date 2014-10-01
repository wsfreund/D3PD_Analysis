function matchedFilterStruct = MatchedFilterTrain(h0Data,h1Data,...
  varargin)
%
% TODO Help
%

% - Creation Date: Wed, 01 Oct 2014
% - Last Modified: Wed, 01 Oct 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  defopts = struct(...
    ... % Noise whitening options:
    'whiteningMatrix',[],...
    'whiteningMean',[],...
    ... % Implementation method:
    'implementation','deterministic',...
    ... % Deterministic option:
    'deterministicExtractionMethod','mean',...
    ... % Stochastic options:
    'N0',[],'percEnergy',.95,...
    'scaleNoise',false...
    );

  if nargin>2
    iCell = cellfun(@iscell,varargin);
    idx = find(iCell);
    for k = idx
      varargin(k) = {varargin(k)};
    end
    inputopts = struct(varargin{:});
  elseif nargin==2
    inputopts = varargin{1};
  else
    inputopts = struct; 
  end

  opts = scanparam(defopts,inputopts);
  matchedFilterStruct.opts = opts;

  % Check if user requested whitening:
  if ~isempty(opts.whiteningMean)
    % Remove noise mean:
    h0Data = bsxfun(@minus,h0Data,opts.whiteningMean);
    h1Data = bsxfun(@minus,h1Data,opts.whiteningMean);
  end

  if ~isempty(opts.whiteningMatrix)
    % Remove noise mean:
    h0Data = opts.whiteningMatrix*h0Data;
    h1Data = opts.whiteningMatrix*h1Data;
  end

  switch opts.deterministicExtractionMethod
  case 'mean'
    %Output.INFO('Using mean of data as match parameter');
    matchedFilterStruct.matchS0 = mean(h0Data,2);
    matchedFilterStruct.matchS1 = mean(h1Data,2);
  case 'maxCorrelation'
    %Output.INFO('Using maxVariance of data as match parameter');
    matchedFilterStruct.matchS0 = h0Data(:,getMaxCorrIdx(h0Data));
    matchedFilterStruct.matchS1 = h1Data(:,getMaxCorrIdx(h1Data));
  otherwise 
    Output.ERROR('D3PDAnalysis:MatchedFilterTrain:NeededArgument',...
      'Unknown method %s',opts.deterministicExtractionMethod)
  end
  matchedFilterStruct.normS0 = sum(matchedFilterStruct.matchS0.^2)^(1/2);
  matchedFilterStruct.normS1 = sum(matchedFilterStruct.matchS1.^2)^(1/2);
  matchedFilterStruct.unscaledS0 = matchedFilterStruct.matchS0;
  matchedFilterStruct.unscaledS1 = matchedFilterStruct.matchS1;
  % Normalize components to unit area:
  matchedFilterStruct.matchS0 = matchedFilterStruct.matchS0 / ...
    matchedFilterStruct.normS0;
  matchedFilterStruct.matchS1 = matchedFilterStruct.matchS1 / ...
    matchedFilterStruct.normS1;

  if strcmp(opts.implementation,'stochastic')
    if isempty(opts.N0)
      Output.ERROR('D3PDAnalysis:MatchedFilterTrain:NeededArgument',...
        ['N0 is not available. It is needed for the '...
          'MatchedFilter training.']);
    end
    [matchedFilterStruct.phi0,~,...
      matchedFilterStruct.lambda0square,~,...
      matchedFilterStruct.energyExplained0,...
      matchedFilterStruct.dataMean0] = ...
      pca(h0Data');
    matchedFilterStruct.phi0 = ...
      matchedFilterStruct.phi0';
    matchedFilterStruct.lambda0square = ...
      matchedFilterStruct.lambda0square';
    matchedFilterStruct.energyExplained0 = ...
      matchedFilterStruct.energyExplained0';
    matchedFilterStruct.dataMean0 = ...
      matchedFilterStruct.dataMean0';

    [matchedFilterStruct.phi1,~,...
      matchedFilterStruct.lambda1square,~,...
      matchedFilterStruct.energyExplained1,...
      matchedFilterStruct.dataMean1] = ...
      pca(h1Data');
    matchedFilterStruct.phi1 = ...
      matchedFilterStruct.phi1';
    matchedFilterStruct.lambda1square = ...
      matchedFilterStruct.lambda1square';
    matchedFilterStruct.energyExplained1 = ...
      matchedFilterStruct.energyExplained1';
    matchedFilterStruct.dataMean1 = ...
      matchedFilterStruct.dataMean1';

    energyCut = matchedFilterStruct.opts.percEnergy;
    matchedFilterStruct.nCompH0d = getNumberOfComponents(...
      matchedFilterStruct.energyExplained0,energyCut);
    matchedFilterStruct.nCompH1d = getNumberOfComponents(...
      matchedFilterStruct.energyExplained1,energyCut);
  end

end

function nComp = getNumberOfComponents(energyExplained,energyCut)
  if isnumeric(energyCut)
    nComp = find(cumsum(energyExplained)>energyCut,1,'first');
  elseif ischar(energyCut)
    Output.ERROR('D3PDAnalysis:MatchedFilterTrain',...
      'String energy cut is not yet implemented.');
  else
    Output.ERROR('D3PDAnalysis:MatchedFilterTrain',...
      'Unknown option')
  end
end

function maxCoefIdx = getMaxCorrIdx(in)
  try
    [~,maxCoefIdx] = max(sum(abs(corr(in,in))));
  catch 
    maxCorrCoef = 0;
    maxCoefIdx = 0;
    for k = 1:size(in,2)
      corrCoefSum = sum(abs(corr(in,in(:,k))));
      if maxCorrCoef < corrCoefSum
        maxCorrCoef = corrCoefSum;
        maxCoefIdx = k;
      end
    end
  end
end
