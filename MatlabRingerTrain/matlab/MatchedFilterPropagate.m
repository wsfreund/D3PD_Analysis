function filterAns = MatchedFilterPropagate(matchedFilterStruct,...
  inData)
%
% TODO Help
%

% - Creation Date: Wed, 01 Oct 2014
% - Last Modified: Thu, 02 Oct 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  opts = matchedFilterStruct.opts;

  % Check if user requested whitening:
  if ~isempty(opts.whiteningMean)
    % Remove noise mean:
    inData = bsxfun(@minus,inData,opts.whiteningMean);
    % Decorrelate:
    inData = opts.whiteningMatrix*inData;
    % White:
    inData = bsxfun(@times,inData,opts.whiteningScale);
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
    % Facilitate access to some variables:
    N0 = opts.N0;
    matchedFilterStruct.nCompH0d = 100;
    matchedFilterStruct.nCompH1d = 100;
    compArray0 = 1:matchedFilterStruct.nCompH0d;
    compArray1 = 1:matchedFilterStruct.nCompH1d;
    % Ir : for Ir we work on the sample without the mean, since we
    % removed it for the pca calculation:
    if opts.scaleNoise
      scaledNoise0 = N0*nCompH0d/...
        (numel(matchedFilterStruct.lambda0square)*2);
      scaledNoise1 = N0*nCompH1d/...
        (numel(matchedFilterStruct.lambda1square)*2);
    else
      scaledNoise0 = N0/2;
      scaledNoise1 = N0/2;
    end
    %I0rNotNorm = (matchedFilterStruct.lambda0square(compArray0) ./ ...  % Scale factor
    %    (matchedFilterStruct.lambda0square(compArray0)+scaledNoise0))* ...
    %    (matchedFilterStruct.phi0(compArray0,:)* ... % Project data
    %    bsxfun(@minus,inData,matchedFilterStruct.dataMean0)).^2
    %

    %I1rNotNorm = (matchedFilterStruct.lambda1square(compArray1)./...    % Scale factor
    %    (matchedFilterStruct.lambda1square(compArray1)+scaledNoise1))* ...
    %    (matchedFilterStruct.phi1(compArray1,:)* ... % Project data
    %    bsxfun(@minus,inData,matchedFilterStruct.dataMean1)).^2

    %I0Norm = I0rNotNorm/N0
    %I1Norm = I1rNotNorm/N0

    %for k=compArray0
    %  keyboard
    %  k
    %  scaleFactor = (matchedFilterStruct.lambda0square(k) ./ ...  % Scale factor
    %    (matchedFilterStruct.lambda0square(k)+scaledNoise0));
    %  arrayKAns = (scaleFactor*matchedFilterStruct.phi0(k,:)*...
    %  bsxfun(@minus,inData,matchedFilterStruct.dataMean0)).^2
    %  arrayKAnsNorm = (scaleFactor*matchedFilterStruct.phi0(k,:)*...
    %  bsxfun(@minus,inData,matchedFilterStruct.dataMean0)).^2/N0
    %end

    Ir = ...
      ... % Ir0:
      (...
        (matchedFilterStruct.lambda0square(compArray0) ./ ...  % Scale factor
        (matchedFilterStruct.lambda0square(compArray0)+scaledNoise0))* ...
        (matchedFilterStruct.phi0(compArray0,:)* ... % Project data
        bsxfun(@minus,inData,matchedFilterStruct.dataMean0)).^2 ... % Take square from the projected data
        - ... % Ir1:
        (matchedFilterStruct.lambda1square(compArray1)./...    % Scale factor
        (matchedFilterStruct.lambda1square(compArray1)+scaledNoise1))* ...
        (matchedFilterStruct.phi1(compArray1,:)* ... % Project data
        bsxfun(@minus,inData,matchedFilterStruct.dataMean1)).^2 ... % Take square from the projected data
      )/N0 % And normalize everything by N0
    Id

    % Filter answer is the sum from the deterministic component and 
    filterAns = Ir + Id; 
  end
end




