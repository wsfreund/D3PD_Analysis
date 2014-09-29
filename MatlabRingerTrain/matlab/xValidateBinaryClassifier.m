function xValidateAnalysis = xValidateBinaryClassifier(...
    sgn,bkg,varargin)
% function [xValidateAnalysis] = trainMany(sgn,bkg,opts)


% - Creation Date: Fri, 26 Sep 2014
% - Last Modified: Mon, 29 Sep 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  if nargin < 2
    Output.ERROR('D3PD_Analysis:WrongInputs',...
      'You must specify at least signal and background dataset.');
  end

  defopts = struct('paramOpts',struct(...
    'xValParam',5:20,'classifierStr','ffnn-matlab'),...
    'n_clusters',10,'n_clusters_train',6,...
    'n_clusters_val',2,...
    'testSgnData',[],'testBkgData',[],...
    'kfold',10,'nInit',100,...
    'debug',false,'norm','norm1',...
    'rocStep',0.001,'evalTime',true,...
    'retrainAfterCrossValWithValData',true,...
    'valFigStr','',...
    'saveStr','');

  if nargin>3
    iCell = cellfun(@iscell,varargin);
    idx = find(iCell);
    for k = idx
      varargin(k) = {varargin(k)};
    end
    inputopts = struct(varargin{:});
  elseif nargin==3
    inputopts = varargin{1};
  else
    inputopts = struct; 
  end

  if isfield(inputopts,'testDataSgnData')
    defopts.n_clusters_val = 1;
    defopts.n_clusters_train = 9;
  end

  opts = scanparam(defopts,inputopts);

  if isempty(opts.paramOpts.classifierStr)
    Output.ERROR('Classifier not specified');
  end

  if isempty(opts.paramOpts.xValParam)
    Output.ERROR('xValParam not specified');
  end

  if ~isempty(opts.saveStr) && (opts.saveStr(1) ~= '_')
    opts.saveStr = ['_' opts.saveStr];
  end

  % Make some checks:
  if (~isempty(opts.testBkgData) && ...
      opts.n_clusters_train + opts.n_clusters_val ...
      ~= opts.n_clusters)
    error('D3PD_Analysis:trainMany',...
      ['The sum of train clusters and val clusters should be the '...
      'same as the n_clusters']);
  end

  if (isempty(opts.testBkgData) && ...
      opts.n_clusters_train + opts.n_clusters_val >= opts.n_clusters)
    error('D3PD_Analysis:trainMany',...
      ['The sum of train clusters, val clusters and tst clusters '...
      'should be the same as the n_clusters']);
  end

  if size(sgn,1) ~= size(bkg,1)
    Output.ERROR('D3PD_Analysis:DifferentPatternSize',...
      'All classes must have the same pattern size.');
  end

  if opts.debug
    if size(sgn,2)>100
      sgn = sgn(:,1:100);
    end
    if size(opts.testSgnData,2)>100
      opts.testSgnData = opts.testSgnData(:,1:100);
    end
    if size(opts.testBkgData,2)>100
      opts.testBkgData = opts.testBkgData(:,1:100);
    end
    if size(bkg,2)>100
      bkg = bkg(:,1:100);
    end
    if ~isfield(inputopts,'paramOpts') || ...
        (isfield(inputopts,'paramOpts') && ...
        ~isfield(inputopts.paramOpts,'debug'))
      opts.paramOpts.debug = true;
    end
  end


	switch opts.norm
	case 'norm1'
    sgn = bsxfun(@rdivide,sgn,sum(sgn,1)+eps);
    bkg = bsxfun(@rdivide,bkg,sum(bkg,1)+eps);
    opts.testSgnData = bsxfun(@rdivide,opts.testSgnData,...
      sum(opts.testSgnData,1)+eps);
    opts.testBkgData = bsxfun(@rdivide,opts.testBkgData,...
      sum(opts.testBkgData,1)+eps);
	end

  xValidateAnalysis.xValInfo.n_clusters = opts.n_clusters;
  xValidateAnalysis.opts = opts;

  if ~isempty(xValidateAnalysis.opts.testSgnData)
    xValidateAnalysis.opts.testSgnData = true;
  else
    xValidateAnalysis.opts.testSgnData = false;
  end
  if ~isempty(xValidateAnalysis.opts.testBkgData)
    xValidateAnalysis.opts.testBkgData = true;
  else
    xValidateAnalysis.opts.testBkgData = false;
  end

  sgn_cl_size = floor(size(sgn,2)/opts.n_clusters);
  bkg_cl_size = floor(size(bkg,2)/opts.n_clusters);

  xValidateAnalysis.sgn_cl_size = sgn_cl_size;
  xValidateAnalysis.bkg_cl_size = bkg_cl_size;

  Output.INFO('Cluster size for signal is: %d',...
    xValidateAnalysis.sgn_cl_size)
  Output.INFO('Cluster size for background is: %d',...
    xValidateAnalysis.bkg_cl_size)

  total=numel(opts.paramOpts.xValParam);


  % Keep all performance information in memory for Validation
  % best threshold {Trn,Val,Tst,AllData}:
  thresVal = zeros(total,opts.kfold,opts.nInit);
  rocArOnThresVal = zeros(total,opts.kfold,opts.nInit);
  SpOnThresVal = zeros(total,opts.kfold,opts.nInit);
  DetOnThresVal = zeros(total,opts.kfold,opts.nInit);
  FaOnThresVal = zeros(total,opts.kfold,opts.nInit);
  bestInitMatrixVal = zeros(total,opts.kfold);

  timeMatrix = zeros(total,opts.kfold,opts.nInit);

  % Keep all performance information in memory for Tstidation
  % best threshold {Trn,Tst,Tst,AllData}:
  thresTst = zeros(total,opts.kfold);
  rocArOnThresTst = zeros(total,opts.kfold);
  SpOnThresTst = repmat({zeros(total,opts.kfold)},1,2);
  DetOnThresTst = repmat({zeros(total,opts.kfold)},1,2);
  FaOnThresTst = repmat({zeros(total,opts.kfold)},1,2);

  allKFoldClassifiers = cell(total,opts.kfold);
  allTrainInfo = cell(total,opts.kfold,opts.nInit);

  meanSPVal = zeros(1,total);
  stdSPVal = zeros(1,total);

  % FIXME Add check to see if this cross-validation possibilities is
  % greater than number of kfolds

  for iParam = 1:total

    xValField = genvarname(sprintf('xValParam_%d',iParam));

    alreadyValidatedPerm = zeros(opts.kfold,2*opts.n_clusters);

    %parfor cFold = 1:opts.kfold
    for cFold = 1:opts.kfold

      % Save this cross validation:
      classField = genvarname(sprintf('classifier_kFold%d',cFold));
      trainInfoField = genvarname(sprintf('trnInfo_kFold%d',cFold));

      % Only run train if validation is unique:
      while(true)
        perm_sgn = randperm(opts.n_clusters);
        perm_bkg = randperm(opts.n_clusters);
        if ~any(all(...
              bsxfun(@eq,alreadyValidatedPerm,[perm_sgn perm_bkg]),2 ...
            ))
          alreadyValidatedPerm(cFold,:) = [perm_sgn perm_bkg];
          break;
        else
          Output.DEBUG(...
            'Attempted to run same cross-validation twice.');
          %alreadyValidatedPerm
          %[perm_sgn perm_bkg]
        end
      end

      tmp_sgn_trn_clusters = perm_sgn(...
        1:opts.n_clusters_train);
      tmp_sgn_val_clusters = perm_sgn(...
        opts.n_clusters_train+1:...
        opts.n_clusters_train+opts.n_clusters_val);
      tmp_sgn_tst_clusters = perm_sgn(...
        opts.n_clusters_train+opts.n_clusters_val+1:end);

      tmp_bkg_trn_clusters = perm_bkg(...
        1:opts.n_clusters_train);
      tmp_bkg_val_clusters = perm_bkg(...
        opts.n_clusters_train+1:...
        opts.n_clusters_train+opts.n_clusters_val);
      tmp_bkg_tst_clusters = perm_bkg(...
        opts.n_clusters_train+opts.n_clusters_val+1:end);

      xValidateAnalysis.xValInfo.(xValField)...
        .(trainInfoField).sgn_trn_clusters = tmp_sgn_trn_clusters;
      xValidateAnalysis.xValInfo.(xValField)...
        .(trainInfoField).sgn_val_clusters = tmp_sgn_val_clusters;
      xValidateAnalysis.xValInfo.(xValField)...
        .(trainInfoField).sgn_tst_clusters = tmp_sgn_tst_clusters;

      xValidateAnalysis.xValInfo.(xValField)...
        .(trainInfoField).bkg_trn_clusters = tmp_bkg_trn_clusters;
      xValidateAnalysis.xValInfo.(xValField)...
        .(trainInfoField).bkg_val_clusters = tmp_bkg_val_clusters;
      xValidateAnalysis.xValInfo.(xValField)...
        .(trainInfoField).bkg_tst_clusters = tmp_bkg_tst_clusters;
 
      % Get standartization params from train dataset
      switch opts.norm
      case 'mapstd'
        [~,trn_ps] = mapstd(...
          [...
            sgn(:,create_cluster(...
              xValidateAnalysis.sgn_cl_size,...
              xValidateAnalysis.xValInfo.(xValField).(trainInfoField)...
             .sgn_trn_clusters)),...
            bkg(:,create_cluster(...
              xValidateAnalysis.bkg_cl_size,...
              xValidateAnalysis.xValInfo.(xValField).(trainInfoField)...
              .bkg_trn_clusters))...
          ]...
        );
        % Apply it. 
        sgn_norm = mapstd('apply',sgn,trn_ps);
        bkg_norm = mapstd('apply',bkg,trn_ps);
        testSgnData_norm = mapstd('apply',opts.testSgnData,trn_ps);
        testBkgData_norm = mapstd('apply',opts.testBkgData,trn_ps);
      case 'norm1'
        sgn_norm = sgn;
        bkg_norm = bkg;
        testSgnData_norm = opts.testSgnData;
        testBkgData_norm = opts.testBkgData;
      otherwise
        Output.ERROR('D3PD_Analysis:UnknownNormalization',...
          'Normalization %s is not available.',opts.norm);
      end

      maxSPVal_forThisKFold = 0;

      % Determine data struct for this Val:
      dataStruct = struct('sgn',sgn_norm,...
        'bkg',bkg_norm,...
        'sgn_cl_size',sgn_cl_size,...
        'bkg_cl_size',bkg_cl_size,...
        'sgn_trn_clusters',tmp_sgn_trn_clusters,... 
        'sgn_val_clusters',tmp_sgn_val_clusters,...
        'sgn_tst_clusters',tmp_sgn_tst_clusters,...
        'bkg_trn_clusters',tmp_bkg_trn_clusters,... 
        'bkg_val_clusters',tmp_bkg_val_clusters,...
        'bkg_tst_clusters',tmp_bkg_tst_clusters,...
        'testSgnData',testSgnData_norm,...
        'testBkgData',testBkgData_norm,...
        'xValParam',opts.paramOpts.xValParam(iParam),...
        'useTstAsValidation',false);
      
      %parfor cInit = 1:opts.nInit
      for cInit = 1:opts.nInit
        Output.INFO(...
          ['Training %s with xValParam %f'...
            ' (kfold %d/%d|initialization %d/%d):'],...
            opts.paramOpts.classifierStr,...
            opts.paramOpts.xValParam(iParam),cFold,opts.kfold,...
            cInit,opts.nInit);

        [tmpClassifier,allTrainInfo{iParam,cFold,cInit}] = ... 
          trainBinaryClassifier(dataStruct,opts.paramOpts);

        timeMatrix(iParam,cFold,cInit) = allTrainInfo{...
          iParam,cFold,cInit}.trainTime;

        % Get Val efficiency:
        [thresVal(iParam,cFold,cInit),...
          SpOnThresVal(iParam,cFold,cInit),...
          DetOnThresVal(iParam,cFold,cInit),...
          FaOnThresVal(iParam,cFold,cInit),...
          rocArOnThresVal(iParam,cFold,cInit)] = ...
          getThresAndEff(tmpClassifier,dataStruct,'val');

        % The initializations are evaluated for validation dataset:
        if SpOnThresVal(iParam,cFold,cInit) > maxSPVal_forThisKFold
          maxSPVal_forThisKFold = SpOnThresVal(iParam,cFold,cInit);
          xValidateAnalysis.xValInfo.(xValField)...
            .(classField) = tmpClassifier;
          xValidateAnalysis.xValInfo.(xValField)...
            .(trainInfoField).trainInfo = ...
            allTrainInfo{iParam,cFold,cInit}; 
          bestInit = cInit;
        end
      end

      % Once defined the best initialized classifier, get its test
      % efficiency and its allData (to determine operation classifier) 
      % efficiency operation on the test threshold:
      [thresTst(iParam,cFold),...
        SpOnThresTst{1}(iParam,cFold),...
        DetOnThresTst{1}(iParam,cFold),...
        FaOnThresTst{1}(iParam,cFold),...
        rocArOnThresTst(iParam,cFold)] = ...
        getThresAndEff(...
          xValidateAnalysis.xValInfo.(xValField).(classField),...
          dataStruct,'tst');

      [SpOnThresTst{2}(iParam,cFold),...
        DetOnThresTst{2}(iParam,cFold),...
        FaOnThresTst{2}(iParam,cFold)] = ...
        getEffAtThres(thresTst(iParam,cFold),...
          xValidateAnalysis.xValInfo.(xValField).(classField),...
          dataStruct,'allData');

      switch opts.norm
      case 'mapstd'
        xValidateAnalysis.xValInfo.(xValField).(classField).userdata...
          .trn_ps = trn_ps;
      end
      xValidateAnalysis.xValInfo.(xValField).(classField).userdata...
        .thresVal = thresVal(iParam,cFold,bestInit);
      xValidateAnalysis.xValInfo.(xValField).(classField).userdata...
        .thresTst = thresTst(iParam,cFold);

      xValidateAnalysis.xValInfo.(xValField).(trainInfoField)...
        .bestInit = bestInit;
      bestInitMatrixVal(iParam,cFold) = bestInit;

      allKFoldClassifiers{iParam,cFold} = xValidateAnalysis...
        .xValInfo.(xValField).(classField);

      %% Remove standartization 
      %sgn = mapstd('reverse',sgn,trn_ps);
      %bkg = mapstd('reverse',bkg,trn_ps);
    end

    meanSPVal(iParam) = mean(SpOnThresVal(...
      iParam,:,xValidateAnalysis.xValInfo.(xValField)...
      .(trainInfoField).bestInit));
    stdSPVal(iParam) = std(SpOnThresVal(...
      iParam,:,xValidateAnalysis.xValInfo.(xValField)...
      .(trainInfoField).bestInit));

    xValidateAnalysis.xValInfo.meanSPVal(iParam) = ...
      meanSPVal(iParam);
    xValidateAnalysis.xValInfo.stdSPVal(iParam) = ...
      stdSPVal(iParam);

    xValidateAnalysis.xValInfo.meanTime(iParam) = ...
      mean(reshape(timeMatrix(iParam,:,:),1,[]));

    xValidateAnalysis.xValInfo.stdTime(iParam) = ...
      std(reshape(timeMatrix(iParam,:,:),1,[]));

    save(sprintf('xValidateAnalysis%s',opts.saveStr),...
      'xValidateAnalysis');
  
  end

  Output.INFO('Finished Cross-Validation for classifier %s.',...
    opts.paramOpts.classifierStr);

  % Save progress info:
  xValidateAnalysis.xValInfo.allTrainInfo = allTrainInfo;
  xValidateAnalysis.xValInfo.allKFoldClassifiers = ...
    allKFoldClassifiers;
  % Validation:
  xValidateAnalysis.xValInfo.thresVal = thresVal;
  xValidateAnalysis.xValInfo.rocArOnThresVal = rocArOnThresVal;
  xValidateAnalysis.xValInfo.SpOnThresVal = SpOnThresVal;
  xValidateAnalysis.xValInfo.DetOnThresVal = DetOnThresVal;
  xValidateAnalysis.xValInfo.FaOnThresVal = FaOnThresVal;
  xValidateAnalysis.xValInfo.bestInitMatrixVal = bestInitMatrixVal;

  xValidateAnalysis.xValInfo.timeMatrix = timeMatrix;

  % Test:
  xValidateAnalysis.xValInfo.thresTst = thresTst;
  xValidateAnalysis.xValInfo.rocArOnThresTst = rocArOnThresTst;
  xValidateAnalysis.xValInfo.SpOnThresTst = SpOnThresTst;
  xValidateAnalysis.xValInfo.DetOnThresTst = DetOnThresTst;
  xValidateAnalysis.xValInfo.FaOnThresTst = FaOnThresTst;

  % Save for reference, the xValParam tested:
  xValidateAnalysis.xValInfo.xValParam = opts.paramOpts.xValParam;
  % Get best xValParam, using highest mean SP for each xValParam:
  [maxMeanSPVal,maxMeanSPValParamIdx] = ...
    max(xValidateAnalysis.xValInfo.meanSPVal);
  % Save it on the struct:
  xValidateAnalysis.bestXVal.maxMeanSPVal = maxMeanSPVal;
  % Save best xVal param:
  xValidateAnalysis.bestXVal.bestxValParam = ...
    opts.paramOpts.xValParam(maxMeanSPValParamIdx);
  xValidateAnalysis.bestXVal.bestxValParamIdx = ...
    maxMeanSPValParamIdx;

  % Get best xVal field:
  bestxValField = genvarname(sprintf('xValParam_%d',...
    xValidateAnalysis.bestXVal.bestxValParamIdx));
  xValidateAnalysis.bestXVal.accessField = ...
    bestxValField;
  % For the best xVal, get test efficiency vector, its mean, std, min
  % and max.
  xValidateAnalysis.bestXVal.thresTst = ...
    thresTst(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.TstRocArOnThresTst = ...
    rocArOnThresTst(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.TstSpOnThresTst = ...
    SpOnThresTst{1}(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.TstSpOnThresTstMean = ...
    mean(SpOnThresTst{1}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.TstSpOnThresTstStd = ...
    std(SpOnThresTst{1}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.TstDetOnThresTst = ...
    DetOnThresTst{1}(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.TstDetOnThresTstMean = ...
    mean(DetOnThresTst{1}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.TstDetOnThresTstStd = ...
    std(DetOnThresTst{1}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.TstFaOnThresTst = ...
    FaOnThresTst{1}(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.TstFaOnThresTstMean = ...
    mean(FaOnThresTst{1}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.TstFaOnThresTstStd = ...
    std(FaOnThresTst{1}(maxMeanSPValParamIdx,:));
  % And get operation efficiency:
  xValidateAnalysis.bestXVal.AllDataSpOnThresTst = ...
    SpOnThresTst{2}(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.AllDataSpOnThresTstMean = ...
    mean(SpOnThresTst{2}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.AllDataSpOnThresTstStd = ...
    std(SpOnThresTst{2}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.AllDataDetOnThresTst = ...
    DetOnThresTst{2}(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.AllDataDetOnThresTstMean = ...
    mean(DetOnThresTst{2}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.AllDataDetOnThresTstStd = ...
    std(DetOnThresTst{2}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.AllDataFaOnThresTst = ...
    FaOnThresTst{2}(maxMeanSPValParamIdx,:);
  xValidateAnalysis.bestXVal.AllDataFaOnThresTstMean = ...
    mean(FaOnThresTst{2}(maxMeanSPValParamIdx,:));
  xValidateAnalysis.bestXVal.AllDataFaOnThresTstStd = ...
    std(FaOnThresTst{2}(maxMeanSPValParamIdx,:));

  [xValidateAnalysis.bestXVal.operationalClassifier...
    .AllDataSPOnTestThres,...
    xValidateAnalysis.bestXVal.operationalClassifier...
    .operationalClassifierIdx] = ...
    max(xValidateAnalysis.bestXVal.AllDataSpOnThresTst);
  xValidateAnalysis.bestXVal.operationalClassifier.accessField = ...
    genvarname(sprintf('classifier_kFold%d',...
    xValidateAnalysis.bestXVal.operationalClassifier...
    .operationalClassifierIdx));
  xValidateAnalysis.bestXVal.operationalClassifier...
    .accessTrainInfoField = ...
    genvarname(sprintf('trnInfo_kFold%d',...
    xValidateAnalysis.bestXVal.operationalClassifier...
    .operationalClassifierIdx));

  % Get operational classifier:
  xValidateAnalysis.bestXVal.operationalClassifier...
    .classifier = xValidateAnalysis.xValInfo...
      .(xValidateAnalysis.bestXVal.accessField)...
      .(xValidateAnalysis.bestXVal.operationalClassifier.accessField);

  % Make its train information easy to access:
  xValidateAnalysis.bestXVal.operationalClassifier...
    .trnInfo = xValidateAnalysis.xValInfo...
      .(xValidateAnalysis.bestXVal.accessField)...
      .(xValidateAnalysis.bestXVal.operationalClassifier...
      .accessTrainInfoField);

  xValidateAnalysis.analyse.plotXValSPFigure = ...
    @() plotXValSPFigure(xValidateAnalysis,opts);
  xValidateAnalysis.analyse.plotXValTimeFigure = ...
    @() plotXValTimeFigure(xValidateAnalysis,opts);
  xValidateAnalysis.analyse.plotTrainEvolution = ...
    @() plotTrainEvolution(xValidateAnalysis,opts);

  figH = xValidateAnalysis.analyse.plotXValSPFigure();
  saveas(figH, ...
    sprintf('%s-CrossVal_SP%s',...
    opts.paramOpts.classifierStr,...
    opts.saveStr),...
    'fig');
  close(figH)
  figH = xValidateAnalysis.analyse.plotXValTimeFigure();
  saveas(figH, ...
    sprintf('%s-CrossVal_Time%s',...
    opts.paramOpts.classifierStr,...
    opts.saveStr),...
    'fig');
  close(figH)

  if opts.retrainAfterCrossValWithValData
    % Re-run train over train and validation dataset. It will use all
    % cross validation and use nInit reinitializations.

    % Keep all performance information in memory for Tstidation
    % best threshold {Trn,Tst,Tst,AllData}:
    thresTst = zeros(opts.kfold,opts.nInit);
    rocArOnThresTst = zeros(opts.kfold,opts.nInit);
    SpOnThresTst = {zeros(opts.kfold,opts.nInit),zeros(1,opts.kfold)};
    DetOnThresTst = {zeros(opts.kfold,opts.nInit),zeros(1,opts.kfold)};
    FaOnThresTst = {zeros(opts.kfold,opts.nInit),...
      zeros(1,opts.kfold)};

    thresTstArray = zeros(1,opts.kfold);
    rocArOnThresTstArray = zeros(1,opts.kfold);
    SpOnThresTstArray = zeros(1,opts.kfold);
    DetOnThresTstArray = zeros(1,opts.kfold);
    FaOnThresTstArray = zeros(1,opts.kfold);

    timeMatrix = zeros(opts.kfold,opts.nInit);

    allTrainInfo = cell(opts.kfold,opts.nInit);
    allKFoldClassifiers = cell(1,opts.kfold);

    bestInitArray = zeros(1,opts.kfold);

    %parfor cFold = 1:opts.kfold
    for cFold = 1:opts.kfold

      % Save this cross tstidation:
      classField = genvarname(sprintf('classifier_kFold%d',cFold));
      trainInfoField = genvarname(sprintf('trnInfo_kFold%d',cFold));

      % For signal dataset:
      % Set validation as train:
      xValidateAnalysis.retrainInfo.(trainInfoField)...
        .sgn_trn_clusters = [xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).sgn_trn_clusters ...
        xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).sgn_val_clusters];
      % Set validation as test
      xValidateAnalysis.retrainInfo.(trainInfoField)...
        .sgn_val_clusters = xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).sgn_tst_clusters;
      % Set test as test
      xValidateAnalysis.retrainInfo.(trainInfoField)...
        .sgn_tst_clusters = xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).sgn_tst_clusters;

      % For background dataset:
      % Set validation as train:
      xValidateAnalysis.retrainInfo.(trainInfoField)...
        .bkg_trn_clusters = [xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).bkg_trn_clusters ...
        xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).bkg_val_clusters];
      % Set validation as test
      xValidateAnalysis.retrainInfo.(trainInfoField)...
        .bkg_val_clusters = xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).bkg_tst_clusters;
      % Set test as test
      xValidateAnalysis.retrainInfo.(trainInfoField)...
        .bkg_tst_clusters = xValidateAnalysis.xValInfo...
        .(bestxValField).(trainInfoField).bkg_tst_clusters;

      tmp_sgn_trn_clusters = xValidateAnalysis.retrainInfo...
        .(trainInfoField).sgn_trn_clusters;
      tmp_sgn_val_clusters = xValidateAnalysis.retrainInfo...
        .(trainInfoField).sgn_val_clusters;
      tmp_sgn_tst_clusters = xValidateAnalysis.retrainInfo...
        .(trainInfoField).sgn_tst_clusters;
      tmp_bkg_trn_clusters = xValidateAnalysis.retrainInfo...
        .(trainInfoField).bkg_trn_clusters;
      tmp_bkg_val_clusters = xValidateAnalysis.retrainInfo...
        .(trainInfoField).bkg_val_clusters;
      tmp_bkg_tst_clusters = xValidateAnalysis.retrainInfo...
        .(trainInfoField).bkg_tst_clusters;

      % Get standartization params from train dataset
      switch opts.norm
      case 'mapstd'
        [~,trn_ps] = mapstd(...
          [...
            sgn(:,create_cluster(...
              xValidateAnalysis.sgn_cl_size,...
              xValidateAnalysis.retrainInfo.(trainInfoField)...
             .sgn_trn_clusters)),...
            bkg(:,create_cluster(...
              xValidateAnalysis.bkg_cl_size,...
              xValidateAnalysis.retrainInfo.(trainInfoField)...
              .bkg_trn_clusters))...
          ]...
        );
        % Apply it. 
        sgn_norm = mapstd('apply',sgn,trn_ps);
        bkg_norm = mapstd('apply',bkg,trn_ps);
        testSgnData_norm = mapstd('apply',opts.testSgnData,trn_ps);
        testBkgData_norm = mapstd('apply',opts.testBkgData,trn_ps);
      case 'norm1'
        sgn_norm = sgn;
        bkg_norm = bkg;
        testSgnData_norm = testSgnData;
        testBkgData_norm = testBkgData;
      otherwise
        Output.ERROR('D3PD_Analysis:UnknownNormalization',...
          'Normalization %s is not available.',opts.norm);
      end

      maxSPTst_forThisKFold = 0;

      % Determine data struct for this Val:
      dataStruct = struct('sgn',sgn_norm,...
        'bkg',bkg_norm,...
        'sgn_cl_size',sgn_cl_size,...
        'bkg_cl_size',bkg_cl_size,...
        'sgn_trn_clusters',tmp_sgn_trn_clusters,... 
        'sgn_val_clusters',tmp_sgn_val_clusters,...
        'sgn_tst_clusters',tmp_sgn_tst_clusters,...
        'bkg_trn_clusters',tmp_bkg_trn_clusters,... 
        'bkg_val_clusters',tmp_bkg_val_clusters,...
        'bkg_tst_clusters',tmp_bkg_tst_clusters,...
        'testSgnData',testSgnData_norm,...
        'testBkgData',testBkgData_norm,...
        'xValParam',opts.paramOpts.xValParam(...
         xValidateAnalysis.bestXVal.bestxValParamIdx),...
        'useTstAsValidation',true);
      
      %parfor cInit = 1:opts.nInit
      for cInit = 1:opts.nInit
        Output.INFO(...
          ['Retraining %s with xValParam %f'...
            ' (kfold %d/%d|initialization %d/%d):'],...
            opts.paramOpts.classifierStr,...
            opts.paramOpts.xValParam(...
              xValidateAnalysis.bestXVal.bestxValParamIdx),...
            cFold,opts.kfold,...
            cInit,opts.nInit);

        [tmpClassifier,allTrainInfo{cFold,cInit}] = ... 
          trainBinaryClassifier(dataStruct,opts.paramOpts);

        timeMatrix(cFold,cInit) = allTrainInfo{cFold,cInit}.trainTime;

        % Get Val efficiency:
        [thresTst(cFold,cInit),...
          SpOnThresTst{1}(cFold,cInit),...
          DetOnThresTst{1}(cFold,cInit),...
          FaOnThresTst{1}(cFold,cInit),...
          rocArOnThresTst(cFold,cInit)] = ...
          getThresAndEff(tmpClassifier,dataStruct,'tst');

        % The initializations are etstuated for tstidation dataset:
        if SpOnThresTst{1}(cFold,cInit) > maxSPTst_forThisKFold
          maxSPTst_forThisKFold = SpOnThresTst{1}(cFold,cInit);
          xValidateAnalysis.retrainInfo...
            .(classField)= tmpClassifier;
          xValidateAnalysis.retrainInfo...
            .(trainInfoField).trainInfo = ...
            allTrainInfo{cFold,cInit}; 
          bestInit = cInit;
        end
      end

      % Once defined the best initialized classifier, get its 
      % allData (to determine operation classifier) 
      % efficiency operation on the test threshold:
      [SpOnThresTst{2}(cFold),...
        DetOnThresTst{2}(cFold),...
        FaOnThresTst{2}(cFold)] = ...
        getEffAtThres(thresTst(cFold),...
          xValidateAnalysis.retrainInfo.(classField),...
          dataStruct,'allData');

      switch opts.norm
      case 'mapstd'
        xValidateAnalysis.retrainInfo.(classField).userdata...
          .trn_ps = trn_ps;
      end
      xValidateAnalysis.retrainInfo.(classField).userdata...
        .thresVal = thresTst(cFold,bestInit);
      xValidateAnalysis.retrainInfo.(classField).userdata...
        .thresTst = thresTst(cFold,bestInit);

      thresTstArray(cFold) = thresTst(cFold,bestInit);
      rocArOnThresTstArray(cFold) = rocArOnThresTst(cFold,bestInit);
      SpOnThresTstArray(cFold) = SpOnThresTst{1}(cFold,bestInit);
      DetOnThresTstArray(cFold) = DetOnThresTst{1}(cFold,bestInit);
      FaOnThresTstArray(cFold) = FaOnThresTst{1}(cFold,bestInit);

      xValidateAnalysis.retrainInfo.(trainInfoField)...
        .bestInit = bestInit;
      bestInitArray(cFold) = bestInit;

      allKFoldClassifiers{cFold} = xValidateAnalysis...
        .retrainInfo.(classField);

      %% Remove standartization 
      %sgn = mapstd('reverse',sgn,trn_ps);
      %bkg = mapstd('reverse',bkg,trn_ps);
    end

    save(sprintf('xValidateAnalysis%s',opts.saveStr),...
      'xValidateAnalysis');
    % Get test efficiency for previous classifier:
    Output.INFO('Finished Cross-Validation for classifier %s.',...
      opts.paramOpts.classifierStr);

    % Save progress info:
    xValidateAnalysis.retrainInfo.bestInitArray = bestInitArray;
    xValidateAnalysis.retrainInfo.allTrainInfo = allTrainInfo;
    xValidateAnalysis.retrainInfo.allKFoldClassifiers = ...
      allKFoldClassifiers;
    % Test:
    xValidateAnalysis.retrainInfo.thresTst = thresTst;
    xValidateAnalysis.retrainInfo.rocArOnThresTst = rocArOnThresTst;
    xValidateAnalysis.retrainInfo.SpOnThresTst = SpOnThresTst;
    xValidateAnalysis.retrainInfo.DetOnThresTst = DetOnThresTst;
    xValidateAnalysis.retrainInfo.FaOnThresTst = FaOnThresTst;

    xValidateAnalysis.retrainInfo.timeMatrix = timeMatrix;

    % For the best xVal, get test efficiency vector, its mean, std, min
    % and max.
    xValidateAnalysis.retrainInfo.thresTst = thresTstArray;
    xValidateAnalysis.retrainInfo.TstRocArOnThresTst = ...
      rocArOnThresTstArray;
    xValidateAnalysis.retrainInfo.TstSpOnThresTst = ...
      SpOnThresTstArray;
    xValidateAnalysis.retrainInfo.TstSpOnThresTstMean = ...
      mean(SpOnThresTstArray);
    xValidateAnalysis.retrainInfo.TstSpOnThresTstStd = ...
      std(SpOnThresTstArray);
    xValidateAnalysis.retrainInfo.TstDetOnThresTst = ...
      DetOnThresTstArray;
    xValidateAnalysis.retrainInfo.TstDetOnThresTstMean = ...
      mean(DetOnThresTstArray);
    xValidateAnalysis.retrainInfo.TstDetOnThresTstStd = ...
      std(DetOnThresTstArray);
    xValidateAnalysis.retrainInfo.TstFaOnThresTst = ...
      FaOnThresTstArray;
    xValidateAnalysis.retrainInfo.TstFaOnThresTstMean = ...
      mean(FaOnThresTstArray);
    xValidateAnalysis.retrainInfo.TstFaOnThresTstStd = ...
      std(FaOnThresTstArray);

    % And get operation efficiency:
    xValidateAnalysis.retrainInfo.AllDataSpOnThresTst = ...
      SpOnThresTst{2};
    xValidateAnalysis.retrainInfo.AllDataSpOnThresTstMean = ...
      mean(SpOnThresTst{2});
    xValidateAnalysis.retrainInfo.AllDataSpOnThresTstStd = ...
      std(SpOnThresTst{2});
    xValidateAnalysis.retrainInfo.AllDataDetOnThresTst = ...
      DetOnThresTst{2};
    xValidateAnalysis.retrainInfo.AllDataDetOnThresTstMean = ...
      mean(DetOnThresTst{2});
    xValidateAnalysis.retrainInfo.AllDataDetOnThresTstStd = ...
      std(DetOnThresTst{2});
    xValidateAnalysis.retrainInfo.AllDataFaOnThresTst = ...
      FaOnThresTst{2};
    xValidateAnalysis.retrainInfo.AllDataFaOnThresTstMean = ...
      mean(FaOnThresTst{2});
    xValidateAnalysis.retrainInfo.AllDataFaOnThresTstStd = ...
      std(FaOnThresTst{2});

    % Operational classifier
    [xValidateAnalysis.retrainInfo.operationalClassifier...
      .AllDataSPOnTestThres,...
      xValidateAnalysis.retrainInfo.operationalClassifier...
      .operationalClassifierIdx] = ...
      max(xValidateAnalysis.retrainInfo.AllDataSpOnThresTst);
    xValidateAnalysis.retrainInfo.operationalClassifier.accessField = ...
      genvarname(sprintf('classifier_kFold%d',...
      xValidateAnalysis.retrainInfo.operationalClassifier...
      .operationalClassifierIdx));
    xValidateAnalysis.retrainInfo.operationalClassifier...
      .accessTrainInfoField = ...
      genvarname(sprintf('trnInfo_kFold%d',...
      xValidateAnalysis.retrainInfo.operationalClassifier...
      .operationalClassifierIdx));

    % Get operational classifier:
    xValidateAnalysis.retrainInfo.operationalClassifier...
      .classifier = xValidateAnalysis.retrainInfo...
        .(xValidateAnalysis.retrainInfo.operationalClassifier.accessField);

    % Make its train information easy to access:
    xValidateAnalysis.retrainInfo.operationalClassifier...
      .trnInfo = xValidateAnalysis.retrainInfo...
        .(xValidateAnalysis.retrainInfo.operationalClassifier...
        .accessTrainInfoField);

  end

  % Check which is the best operational classifier, the retrained or
  % the bestXVal:
  if opts.retrainAfterCrossValWithValData && ...
      (xValidateAnalysis.bestXVal.operationalClassifier...
      .AllDataSPOnTestThres > xValidateAnalysis.retrainInfo...
      .operationalClassifier.AllDataSPOnTestThres)
    xValidateAnalysis.operationalClassifier = ...
      xValidateAnalysis.retrainInfo.operationalClassifier;
  else
    xValidateAnalysis.operationalClassifier = ...
      xValidateAnalysis.bestXVal.operationalClassifier;
  end

  save(sprintf('xValidateAnalysis%s',opts.saveStr),...
    'xValidateAnalysis');

end

function figH = whiteFigure(square)
  if nargin < 1
    square = false;
  end
  if ~square
    figH = figure('Color','w',...
      'NumberTitle','Off','MenuBar','none',...
      'Toolbar','none','Units','normalized','OuterPosition',...
      [0,0,1,1]);
  else
    ss=get(0,'ScreenSize');
    figH = figure('Color','w',...
      'NumberTitle','Off','MenuBar','none',...
      'Toolbar','none','Units','pixels','OuterPosition',...
      [0,0,min(ss(3:4)),min(ss(3:4))]);
    set(figH,'Units','normalized');
  end
  set(figH,'Units','centimeters')
  pos = get(figH,'OuterPosition');
  set(figH,'PaperSize',pos(3:4));
  set(figH,'PaperPosition',[0 0 pos(3:4)]);
  set(figH,'Units','normalized');
end

function figH = plotXValSPFigure(xValidateAnalysis,opts)
  figH = whiteFigure;
  hold on
  eH = errorbar(opts.paramOpts.xValParam,...
    xValidateAnalysis.xValInfo.meanSPVal,...
    xValidateAnalysis.xValInfo.stdSPVal);
  set(eH,'LineWidth',2,'MarkerEdgeColor','r',...
    'MarkerSize',10,'Marker','o');
  title(sprintf('%s %s',opts.paramOpts.classifierStr,...
    opts.valFigStr));
  xlabel(sprintf('Cross-Validation Parameter (%s)',...
    xValidateAnalysis.bestXVal.operationalClassifier.trnInfo...
    .trainInfo.crossValidationParam));
  ylabel('SP (%) on Validation Dataset');
  set(gca,'FontSize',16);
  grid(gca,'on')
  grid(gca,'minor')
  axis(gca,'tight')
  set(gca,'XTickLabel',arrayfun(@(in) num2str(in),...
    opts.paramOpts.xValParam,'Uniform',false),...
    'XTick',opts.paramOpts.xValParam);
  ax=axis;
  if ax(4)>100
    ax(4)=100;
  end
  if ax(3)<0
    ax(3)=0;
  end
  axis(ax)
  hold off
  setappdata(figH,'axesH',gca);
  GraphUtils.NewZoomAndPan(figH);
end

function figH = plotXValTimeFigure(xValidateAnalysis,opts)
  figH = whiteFigure;
  hold on
  eH = errorbar(opts.paramOpts.xValParam,...
    xValidateAnalysis.xValInfo.meanTime,...
    xValidateAnalysis.xValInfo.stdTime);
  set(eH,'LineWidth',2,'MarkerEdgeColor','r',...
    'MarkerSize',10,'Marker','o');
  title(sprintf('%s %s',opts.paramOpts.classifierStr,...
    opts.valFigStr));
  xlabel(sprintf('Cross-Validation Parameter (%s)',...
    xValidateAnalysis.bestXVal.operationalClassifier...
    .trnInfo.trainInfo.crossValidationParam));
  ylabel('Time (s)');
  set(gca,'FontSize',16);
  grid(gca,'on')
  grid(gca,'minor')
  axis(gca,'tight')
  set(gca,'XTickLabel',arrayfun(@(in) num2str(in),...
    opts.paramOpts.xValParam,'Uniform',false),...
    'XTick',opts.paramOpts.xValParam);
  ax=axis;
  if ax(3)<0
    ax(3)=0;
  end
  axis(ax)
  hold off
  setappdata(figH,'axesH',gca);
  GraphUtils.NewZoomAndPan(figH);
end

function figH = plotTrainEvolution(xValidateAnalysis,opts)

  xValParam = xValidateAnalysis.xValInfo.xValParam;

  figH = whiteFigure;
  axesH = zeros(numel(xValParam),1);

  for cLine=1:numel(xValParam)
    axesH(cLine,1) = subplot(numel(xValParam),...
      1,cLine,'Parent',figH);
    set(axesH(cLine,1),'NextPlot','add',... 
      'FontSize',12,'box','off',...
      'Layer','top');
  end

  GraphUtils.setCustomPlotArea(axesH);

  for iParam=1:numel(xValParam)
    xValField = genvarname(sprintf('xValParam_%d',iParam));
    for cFold = 1:opts.kfold
      for cInit = 1:opts.nInit
        % Check if we are on the best initialization for this kFold
        plotStyle = 0;
        if cInit == xValidateAnalysis.xValInfo...
            .bestInitMatrixVal(iParam,cFold)
          plotStyle = 1;
        end
        if iParam == xValidateAnalysis.bestXVal.bestxValParamIdx ...
            && cInit == xValidateAnalysis.bestXVal...
            .operationalClassifier.operationalClassifierIdx
          plotStyle = 2;
          if cFold == xValidateAnalysis.bestXVal.bestxValParamIdx
            plotStyle = 3;
          end
        end
        xValidateAnalysis.xValInfo.allTrainInfo{iParam,cFold,cInit}...
          .plotTrainEvolution(plotStyle,axesH(iParam));
      end
    end
    set(axesH(iParam,1),'YScale','Log')
    axis(axesH(iParam,1),'tight')
    grid(axesH(iParam,1),'on')
    %grid(axesH(iParam,1),'minor')
    title(axesH(iParam,1),sprintf(...
      'Cross-Validation Param: %f | %s %s ',...
      opts.paramOpts.xValParam(iParam),...
      opts.paramOpts.classifierStr,...
      opts.valFigStr));
    xlabel(axesH(iParam,1),'Iteration')
    ylabel(axesH(iParam,1),'Train Function Cost')
  end

  GraphUtils.NewZoomAndPan(axesH);

end
