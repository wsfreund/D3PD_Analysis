function classifier = trainOAOClassifier(classData,varargin)
%
% TODO Help
%

% - Creation Date: Sun, 28 Sep 2014
% - Last Modified: Mon, 29 Sep 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  defopts = struct('testCell',[],...
    'valFigStr','','saveStr','');

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

  for field = fieldnames(opts)'
    field = field{1};
    inputopts.(field) = opts.(field); % Force field creation if it
    % doesnt exist
  end

  classifier.opts = opts;
  classifier.opts.testCell = [];

  classifier.numOfClasses = numel(classData);

  classifier.OAO_crossVal = cell(classifier.numOfClasses);

  for target1 = 1:classifier.numOfClasses
    for target2 = 1:classifier.numOfClasses
      if target2 <= target1
        continue;
      end

      Output.INFO('Training class %d x %d.',target1,target2);

      sgn = classData{target1};
      bkg = classData{target2};

      % Set test data:
      if ~isempty(opts.testCell)
        sgnTest = opts.testCell{target1};
        bkgTest = opts.testCell{target2};
      else
        sgnTest = [];
        bkgTest = [];
      end

      localInputOpts = inputopts;
      localInputOpts.testSgnData = sgnTest;
      localInputOpts.testBkgData = bkgTest;
      localInputOpts.valFigStr = sprintf('%s | Class %d x %d',...
        opts.valFigStr,target1,target2);
      localInputOpts.saveStr = sprintf('_c%dxc%d',target1,target2);

      classifier.OAO_crossVal{target1,target2} = ...
        xValidateBinaryClassifier(sgn,bkg,localInputOpts);
    end
  end

  Output.INFO('Evaluating OAO joint efficiencies: ');
  classifier.xValParam = classifier.OAO_crossVal{1,2}...
    .opts.paramOpts.xValParam;

  fullDataCell = cell(classifier.numOfClasses,1);
  for cIn = 1:classifier.numOfClasses
    fullDataCell{cIn} = [classData{cIn} opts.testCell{cIn}];
  end

  totalDataTst = cellfun('size',opts.testCell,2);
  totalDataTst = totalDataTst(:);
  totalDataAllData = cellfun('size',fullDataCell,2);
  totalDataAllData = totalDataAllData(:);


  classifier.getDecision = @(varargin) ...
    getDecision(classifier,varargin{:});

  % Get operation classifier decision:
  decisionOperationClassifierTst = classifier.getDecision(...
    opts.testCell);
  decisionOperationClassifierAllData = classifier.getDecision(...
    fullDataCell);

  confusionMatrixTst = zeros(classifier.numOfClasses,...
    classifier.numOfClasses+1);
  confusionMatrixAllData = zeros(classifier.numOfClasses,...
    classifier.numOfClasses+1);
  for cClass1 = 1:classifier.numOfClasses
    for cClass2 = 1:classifier.numOfClasses
      confusionMatrixTst(cClass1,cClass2) = ...
        sum(decisionOperationClassifierTst{cClass1}==cClass2); 
      confusionMatrixAllData(cClass1,cClass2) = ...
        sum(decisionOperationClassifierAllData{cClass1}==cClass2); 
    end
  end
  confusionMatrixTst(:,end) = totalDataTst-sum(confusionMatrixTst,2);
  confusionMatrixTstPerc = bsxfun(@rdivide,...
    confusionMatrixTst,totalDataTst)*100;
  SPTst = sqrt(sum(diag(... % sqrt from the product:
    ... % Arithmeatic mean from detection rates:
    confusionMatrixTstPerc))/...
    classifier.numOfClasses*...
    ... % Geometric mean from detection rates:
    prod(diag(confusionMatrixTstPerc))^...
    (1/classifier.numOfClasses));
  confusionMatrixAllData(:,end) = ...
    totalDataAllData-sum(confusionMatrixAllData,2);
  confusionMatrixAllDataPerc = bsxfun(@rdivide,...
    confusionMatrixAllData,totalDataAllData)*100;
  SPAllData = sqrt(sum(diag(... % sqrt from the product:
    ... % Arithmeatic mean from detection rates:
    confusionMatrixAllDataPerc))/...
    classifier.numOfClasses*...
    ... % Geometric mean from detection rates:
    prod(diag(confusionMatrixAllDataPerc))^...
    (1/classifier.numOfClasses));

  classifier.operationClassifier.confusionMatrixTst = ...
    confusionMatrixTst;
  classifier.operationClassifier.confusionMatrixTstPerc = ...
    confusionMatrixTstPerc;

  classifier.operationClassifier.SPTst = SPTst;

  classifier.operationClassifier.confusionMatrixAllData = ...
    confusionMatrixAllData;
  classifier.operationClassifier.confusionMatrixAllDataPerc = ...
    confusionMatrixAllDataPerc;

  classifier.operationClassifier.SPAllData = SPAllData;

  kfold = classifier.OAO_crossVal{1,2}.opts.kfold;

  if isfield(classifier.OAO_crossVal{1,2},'retrainInfo')
    confusionMatrixTst = repmat(...
      {zeros(classifier.numOfClasses,classifier.numOfClasses+1)},...
      1,kfold);
    confusionMatrixTstPerc = cell(1,kfold);

    confusionMatrixAllData = repmat(...
      {zeros(classifier.numOfClasses,classifier.numOfClasses+1)},...
      1,kfold);
    confusionMatrixAllDataPerc = cell(1,kfold);
    for cFold = 1:kfold
      [decisionTst,labelsTst] = classifier.getDecision(...
        opts.testCell,cFold);
      for cClass1 = 1:classifier.numOfClasses
        for cClass2 = 1:classifier.numOfClasses
          confusionMatrixTst{cFold}(cClass1,cClass2) = ...
            sum(decisionTst{cClass1}==cClass2); 
        end
      end
      % Add conflictant data information:
      confusionMatrixTst{cFold}(:,end) = ...
        totalDataTst-sum(confusionMatrixTst{cFold},2);
      confusionMatrixTstPerc{cFold} = bsxfun(@rdivide,...
        confusionMatrixTst{cFold},totalDataTst)*100;
      SPTst(cFold) = sqrt(sum(diag(... % sqrt from the product:
        ... % Arithmeatic mean from detection rates:
        confusionMatrixTstPerc{cFold}))/...
        classifier.numOfClasses*...
        ... % Geometric mean from detection rates:
        prod(diag(confusionMatrixTstPerc{cFold}))^...
        (1/classifier.numOfClasses));
      % Now run on fullData:
      [decisionAllData,labelsAllData] = classifier.getDecision(...
        fullDataCell,cFold);
      for cClass1 = 1:classifier.numOfClasses
        for cClass2 = 1:classifier.numOfClasses
          confusionMatrixAllData{cFold}(cClass1,cClass2) = ...
            sum(decisionAllData{cClass1}==cClass2); 
        end
      end
      % Add conflictant data information:
      confusionMatrixAllData{cFold}(:,end) = ...
        totalDataAllData-sum(confusionMatrixAllData{cFold},2);
      confusionMatrixAllDataPerc{cFold} = bsxfun(@rdivide,...
        confusionMatrixAllData{cFold},totalDataAllData)*100;
      SPAllData(cFold) = sqrt(sum(diag(... % sqrt from the product:
        ... % Arithmeatic mean from detection rates:
        confusionMatrixAllDataPerc{cFold}))/...
        classifier.numOfClasses*...
        ... % Geometric mean from detection rates:
        prod(diag(confusionMatrixAllDataPerc{cFold}))^...
        (1/classifier.numOfClasses));
    end

    classifier.retrainInfo.confusionMatrixTst = ...
      confusionMatrixTst;
    classifier.retrainInfo.confusionMatrixTstPerc = ...
      confusionMatrixTstPerc;

    classifier.retrainInfo.confusionMatrixTstPercMean = ...
      mean(reshape([confusionMatrixTstPerc{:}],...
      size(confusionMatrixTstPerc{1},1),...
      size(confusionMatrixTstPerc{1},2),[]),3);

    classifier.retrainInfo.confusionMatrixTstPercStd = ...
      std(reshape([confusionMatrixTstPerc{:}],...
      size(confusionMatrixTstPerc{1},1),...
      size(confusionMatrixTstPerc{1},2),[]),[],3);

    classifier.retrainInfo.SPTst = SPTst;
    classifier.retrainInfo.SPTstMean = mean(SPTst);
    classifier.retrainInfo.SPTstStd = std(SPTst);

    classifier.retrainInfo.confusionMatrixAllData = ...
      confusionMatrixAllData;
    classifier.retrainInfo.confusionMatrixAllDataPerc = ...
      confusionMatrixAllDataPerc;

    classifier.retrainInfo.confusionMatrixAllDataPercMean = ...
      mean(reshape([confusionMatrixAllDataPerc{:}],...
      size(confusionMatrixAllDataPerc{1},1),...
      size(confusionMatrixAllDataPerc{1},2),[]),3);

    classifier.retrainInfo.confusionMatrixAllDataPercStd = ...
      std(reshape([confusionMatrixAllDataPerc{:}],...
      size(confusionMatrixAllDataPerc{1},1),...
      size(confusionMatrixAllDataPerc{1},2),[]),[],3);

    classifier.retrainInfo.SPAllData = SPAllData;
    classifier.retrainInfo.SPAllDataMean = mean(SPAllData);
    classifier.retrainInfo.SPAllDataStd = std(SPAllData);

  end

  nParam=numel(classifier.xValParam);

  confusionMatrixTst = repmat(...
    {zeros(classifier.numOfClasses,classifier.numOfClasses+1)},...
    nParam,kfold);
  confusionMatrixTstPerc = cell(nParam,kfold);

  confusionMatrixAllData = repmat(...
    {zeros(classifier.numOfClasses,classifier.numOfClasses+1)},...
    nParam,kfold);
  confusionMatrixAllDataPerc = cell(nParam,kfold);

  for iParam = 1:nParam
    for cFold = 1:kfold
      [decisionTst,labelsTst] = classifier.getDecision(...
        opts.testCell,[iParam,cFold]);
      for cClass1 = 1:classifier.numOfClasses
        for cClass2 = 1:classifier.numOfClasses
          confusionMatrixTst{iParam,cFold}(cClass1,cClass2) = ...
            sum(decisionTst{cClass1}==cClass2); 
        end
      end
      % Add conflictant data information:
      confusionMatrixTst{iParam,cFold}(:,end) = ...
        totalDataTst-sum(confusionMatrixTst{iParam,cFold},2);
      confusionMatrixTstPerc{iParam,cFold} = bsxfun(@rdivide,...
        confusionMatrixTst{iParam,cFold},totalDataTst)*100;
      SPTst(iParam,cFold) = sqrt(sum(diag(... % sqrt from the product:
        ... % Arithmeatic mean from detection rates:
        confusionMatrixTstPerc{iParam,cFold}))/...
        classifier.numOfClasses*...
        ... % Geometric mean from detection rates:
        prod(diag(confusionMatrixTstPerc{iParam,cFold}))^...
        (1/classifier.numOfClasses));
      % Now run on fullData:
      [decisionAllData,labelsAllData] = classifier.getDecision(...
        fullDataCell,[iParam,cFold]);
      for cClass1 = 1:classifier.numOfClasses
        for cClass2 = 1:classifier.numOfClasses
          confusionMatrixAllData{iParam,cFold}(cClass1,cClass2) = ...
            sum(decisionAllData{cClass1}==cClass2); 
        end
      end
      % Add conflictant data information:
      confusionMatrixAllData{iParam,cFold}(:,end) = ...
        totalDataAllData-sum(confusionMatrixAllData{iParam,cFold},2);
      confusionMatrixAllDataPerc{iParam,cFold} = bsxfun(@rdivide,...
        confusionMatrixAllData{iParam,cFold},totalDataAllData)*100;
      SPAllData(iParam,cFold) = sqrt(sum(diag(... % sqrt from the product:
        ... % Arithmeatic mean from detection rates:
        confusionMatrixAllDataPerc{iParam,cFold}))/...
        classifier.numOfClasses*...
        ... % Geometric mean from detection rates:
        prod(diag(confusionMatrixAllDataPerc{iParam,cFold}))^...
        (1/classifier.numOfClasses));
    end
  end

  classifier.xValInfo.confusionMatrixTst = ...
    confusionMatrixTst;
  classifier.xValInfo.confusionMatrixTstPerc = ...
    confusionMatrixTstPerc;

  classifier.xValInfo.xValParamConfusionMatrixTstPercMean = ...
    mean(reshape([confusionMatrixTstPerc{:}],...
    size(confusionMatrixTstPerc{1},1),...
    size(confusionMatrixTstPerc{1},2),...
    size(confusionMatrixTstPerc,2),[]),3);

  classifier.xValInfo.xValParamConfusionMatrixTstPercStd = ...
    std(reshape([confusionMatrixTstPerc{:}],...
    size(confusionMatrixTstPerc{1},1),...
    size(confusionMatrixTstPerc{1},2),...
    size(confusionMatrixTstPerc,2),[]),[],3);

  classifier.xValInfo.SPTst = SPTst;
  classifier.xValInfo.SPTstMean = mean(SPTst,2);
  classifier.xValInfo.SPTstStd = std(SPTst,[],2);

  classifier.xValInfo.confusionMatrixAllData = ...
    confusionMatrixAllData;
  classifier.xValInfo.confusionMatrixAllDataPerc = ...
    confusionMatrixAllDataPerc;

  classifier.xValInfo.confusionMatrixAllDataPercMean = ...
    mean(reshape([confusionMatrixAllDataPerc{:}],...
    size(confusionMatrixAllDataPerc{1},1),...
    size(confusionMatrixAllDataPerc{1},2),...
    size(confusionMatrixAllDataPerc,2),[]),3);

  classifier.xValInfo.confusionMatrixAllDataPercStd = ...
    std(reshape([confusionMatrixAllDataPerc{:}],...
    size(confusionMatrixAllDataPerc{1},1),...
    size(confusionMatrixAllDataPerc{1},2),...
    size(confusionMatrixAllDataPerc,2),[]),[],3);

  classifier.xValInfo.SPAllData = SPAllData;
  classifier.xValInfo.SPAllDataMean = mean(SPAllData,2);
  classifier.xValInfo.SPAllDataStd = std(SPAllData,[],2);

  timeSum = zeros(...
    size(classifier.OAO_crossVal{1,2}.xValInfo.timeMatrix,1),...
    size(classifier.OAO_crossVal{1,2}.xValInfo.timeMatrix,2)*...
    size(classifier.OAO_crossVal{1,2}.xValInfo.timeMatrix,3)...
    );

  for target1 = 1:classifier.numOfClasses
    for target2 = 1:classifier.numOfClasses
      if target2 <= target1
        continue;
      end
      timeSum = timeSum + reshape(classifier.OAO_crossVal{...
        target1,target2}.xValInfo.timeMatrix,...
        size(timeSum,1),size(timeSum,2),size(timeSum,3));
    end
  end

  classifier.xValInfo.timeSum = timeSum;

  classifier.xValInfo.meanTime = mean(timeSum,2);
  classifier.xValInfo.stdTime = std(timeSum,[],2);

  classifier.plotxValParam = @(varargin) plotxValParam(classifier,...
    opts,varargin{:});

  classifier.plotXValTimeFigure = @(varargin) plotXValTimeFigure(...
    classifier,opts);

end

function [decision,labels,out] = getDecision(classifier,inData,...
  classifierTag)

  nonCellData = false;
  if ~iscell(inData)
    nonCellData = true;
    inData = {inData};
  end

  if nargin < 4
    datasetLabel = 'allData';
    if nargin < 3
      classifierTag = 'operationalClassifier';
    end
  end

  OAO_classifiers = cell(classifier.numOfClasses);

  trnInfo = cell(classifier.numOfClasses);

  %useTstAsValidation = false;

  % Get OAO (One Against One) classifiers:
  if ischar(classifierTag)
    switch classifierTag
    case 'operationalClassifier';
      for target1 = 1:classifier.numOfClasses
        for target2 = 1:classifier.numOfClasses
          if target2 <= target1
            continue;
          end
          OAO_classifiers{target1,target2} = classifier...
            .OAO_crossVal{target1,target2}.operationalClassifier...
            .classifier;
          trnInfo{target1,target2} = classifier...
            .OAO_crossVal{target1,target2}.operationalClassifier...
            .trnInfo;
        end
      end
    otherwise
      if ~isnumeric(classifierTag)
        Output.ERROR('D3PDAnalysis:WrongInput',...
          ['classifierTag must either be ''operationalClassifier'' or '...
          'a number indicating it index in case of retrained'...
          ' classifier, and two number in case of crossVal'...
          ' classifier.'])
      end
    end
  else
    switch numel(classifierTag)
    case 1
      %useTstAsValidation = true;
      % Will use retrain information if available
      if ~isfield(classifier.OAO_crossVal{1,2},'retrainInfo')
        Output.ERROR('D3PDAnalysis:retrainInfoNotAvailable',...
          ['Requested to propagate OAO classifier with retrained '...
          'classifier, but it is not available.']);
      end
      cFold = classifierTag(1);
      %classField = genvarname(sprintf('classifier_kFold%d',cFold));
      trainInfoField = genvarname(sprintf('trnInfo_kFold%d',cFold));
      for target1 = 1:classifier.numOfClasses
        for target2 = 1:classifier.numOfClasses
          if target2 <= target1
            continue;
          end
          OAO_classifiers{target1,target2} = classifier...
            .OAO_crossVal{target1,target2}.retrainInfo...
            .allKFoldClassifiers{classifierTag(1)};
          trnInfo{target1,target2} = classifier...
            .OAO_crossVal{target1,target2}.retrainInfo...
            .(trainInfoField);
        end
      end
    case 2
      iParam = classifierTag(1);
      cFold = classifierTag(2);
      xValField = genvarname(sprintf('xValParam_%d',iParam));
      classField = genvarname(sprintf('classifier_kFold%d',cFold));
      trainInfoField = genvarname(sprintf('trnInfo_kFold%d',cFold));
      for target1 = 1:classifier.numOfClasses
        for target2 = 1:classifier.numOfClasses
          if target2 <= target1
            continue;
          end
          OAO_classifiers{target1,target2} = classifier...
            .OAO_crossVal{target1,target2}.xValInfo...
            .allKFoldClassifiers{classifierTag(1),...
            classifierTag(2)};
          trnInfo{target1,target2} = classifier...
            .OAO_crossVal{target1,target2}.xValInfo...
            .(xValField).(trainInfoField);
        end
      end
    otherwise 
      Output.ERROR('D3PDAnalysis:WrongInput',...
        ['If classifierTag request an specific classifier,'...
        ' then it must be numeric and contain only '])
    end
  end

  %if useTstAsValidation && strcmp(datasetLabel,'val')
  %  datasetLabel = 'tst';
  %end
  %if ~isvector(inData)
  %  nIn = size(inData,1); % Case where input is given using nIn x 2
  %  % cells.
  %else
    nIn = numel(inData);
  %end

  out = cell(1,nIn);
  decision = cell(1,nIn);
  for cIn = 1:nIn
    out{cIn}((classifier.numOfClasses...
      *(classifier.numOfClasses-1)/2),size(inData{cIn},2)) = 0;
    labels{cIn} = out{cIn};
  end
  cOut = 1; 
  for target1 = 1:classifier.numOfClasses
    for target2 = 1:classifier.numOfClasses
      if target2 <= target1
        continue;
      end
      %tmpTrnInfo = trnInfo{target1,target2};
      %sgn_cl_size = classifier.OAO_crossVal{...
      %  target1,target2}.sgn_cl_size;
      %bkg_cl_size = classifier.OAO_crossVal{...
      %  target1,target2}.bkg_cl_size;
      for cIn = 1:nIn
        %switch datasetLabel
        %case 'allData'
        %  % Here, there is no discrimination whether the dataset is
        %  % from any of the used during training.
        %  dsIn = [inData{cIn,:}];
        %case 'tst'
        %  % Add second cell data, as it is for testing, but only add
        %  % test clusters from first cell:
        %  usedAsTrain = false;
        %  switch cIn
        %  case target1
        %    usedAsTrain = true;
        %    clusterIdx = create_cluster(sgn_cl_size,...
        %      tmpTrnInfo.sgn_tst_clusters);
        %  case target2
        %    usedAsTrain = true;
        %    clusterIdx = create_cluster(bkg_cl_size,...
        %      tmpTrnInfo.bkg_tst_clusters);
        %  otherwise
        %    % In this case, the dataset is not from any trained
        %    % cells, so it must be added as test:
        %    dsIn = [inData{cIn,:}];
        %  end
        %  if usedAsTrain 
        %    dsIn = [inData{cIn,1}(...
        %      :,clusterIdx) inData{cIn,2}];
        %  end
        %case 'val'
        %  usedAsTrain = false;
        %  switch cIn
        %  case target1
        %    usedAsTrain = true;
        %    clusterIdx = create_cluster(sgn_cl_size,...
        %      tmpTrnInfo.sgn_val_clusters);
        %  case target2
        %    usedAsTrain = true;
        %    clusterIdx = create_cluster(bkg_cl_size,...
        %      tmpTrnInfo.bkg_val_clusters);
        %  otherwise
        %    % In this case, the dataset is not from any trained
        %    % cells, so it must be added as test. Since we are on
        %    % validation dataset, we don''t add it:
        %    dsIn = [];
        %  end
        %  if usedAsTrain 
        %    dsIn = [inData{cIn,1}(:,clusterIdx)];
        %  end
        %case 'trn'
        %  usedAsTrain = false;
        %  switch cIn
        %  case target1
        %    usedAsTrain = true;
        %    clusterIdx = create_cluster(sgn_cl_size,...
        %      tmpTrnInfo.sgn_trn_clusters);
        %  case target2
        %    usedAsTrain = true;
        %    clusterIdx = create_cluster(bkg_cl_size,...
        %      tmpTrnInfo.bkg_trn_clusters);
        %  otherwise
        %    % In this case, the dataset is not from any trained
        %    % cells, so it must be added as test. Since we are on
        %    % training dataset, we don''t add it:
        %    dsIn = [];
        %  end
        %  if usedAsTrain 
        %    dsIn = [inData{cIn,1}(:,clusterIdx)];
        %  end
        %otherwise
        %  Output.ERROR('D3PDAnalysis:WrongInput',...
        %    'Input datasetLabel %s is not a valid option.',...
        %    datasetLabel);
        %end
        switch classifier.OAO_crossVal{target1,target2}.opts.norm
        case 'mapstd'
          normIn = mapstd('apply',inData{cIn},...
            OAO_classifiers{target1,target2}...
            .userdata.trn_ps);
        case 'norm1'
          normIn = bsxfun(@rdivide,inData{cIn},...
            sum(dsIn,1)+eps);
        end
        out{cIn}(cOut,:) = OAO_classifiers{target1,target2}...
          .userdata.outputFun(normIn);
        target1Msk = out{cIn}(cOut,:) > OAO_classifiers{...
          target1,target2}.userdata.thresTst;
        labels{cIn}(cOut,target1Msk) = target1;
        labels{cIn}(cOut,~target1Msk) = target2;
      end
      cOut = cOut + 1;
    end
  end
  for cIn = 1:nIn
    [decision{cIn},~,c] = mode(labels{cIn});
    mskToChange = cellfun('length',c)>1;
    if any(mskToChange)
      decision{cIn}(mskToChange) = 0;
    end
  end

  if nonCellData
    % Give output as arrays instead of cell, if input was not a cell.
    labels = [labels{:}];
    decision = [decision{:}];
    out = [out{:}];
  end

end


function figH = plotxValParam(classifier,opts,varargin)
  if numel(varargin) < 1
    varargin{1} = 'AllData';
  end

  dataset = varargin{1};

  switch dataset
  case {'AllData','alldata'}
    paramMeanToPlot = classifier.xValInfo.SPAllDataMean;
    paramStdToPlot = classifier.xValInfo.SPAllDataStd;
    yLabelStr = 'over All Data';
  case {'Test','tst','Tst'}
    paramMeanToPlot = classifier.xValInfo.SPTstMean;
    paramStdToPlot = classifier.xValInfo.SPTstStd;
    yLabelStr = 'on Test Dataset';
  end

  figH = whiteFigure;
  hold on
  eH = errorbar(classifier.xValParam,...
    paramMeanToPlot,paramStdToPlot);
  set(eH,'LineWidth',2,'MarkerEdgeColor','r',...
    'MarkerSize',10,'Marker','o');
  title(sprintf('%s %s',classifier.OAO_crossVal{1,2}.opts...
    .paramOpts.classifierStr,opts.valFigStr));
  xlabel(sprintf('Cross-Validation Parameter (%s)',...
    classifier.OAO_crossVal{1,2}.bestXVal.operationalClassifier...
    .trnInfo.trainInfo.crossValidationParam));
  ylabel(sprintf('SP (%%) %s',yLabelStr));
  set(gca,'FontSize',16);
  grid(gca,'on')
  grid(gca,'minor')
  axis(gca,'tight')
  set(gca,'XTickLabel',arrayfun(@(in) num2str(in),...
    classifier.xValParam,'Uniform',false),...
    'XTick',classifier.xValParam);
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

function figH = plotXValTimeFigure(classifier,opts)
  figH = whiteFigure;

  hold on
  eH = errorbar(classifier.xValParam,...
    classifier.xValInfo.meanTime,...
    classifier.xValInfo.stdTime);
  set(eH,'LineWidth',2,'MarkerEdgeColor','r',...
    'MarkerSize',10,'Marker','o');
  title(sprintf('%s %s',classifier.OAO_crossVal{1,2}.opts...
    .paramOpts.classifierStr,opts.valFigStr));
  xlabel(sprintf('Cross-Validation Parameter (%s)',...
    classifier.OAO_crossVal{1,2}.bestXVal.operationalClassifier...
    .trnInfo.trainInfo.crossValidationParam));
  ylabel('Time (s)');
  set(gca,'FontSize',16);
  grid(gca,'on')
  grid(gca,'minor')
  axis(gca,'tight')
  set(gca,'XTickLabel',arrayfun(@(in) num2str(in),...
    classifier.xValParam,'Uniform',false),...
    'XTick',classifier.xValParam);
  ax=axis;
  if ax(3)<0
    ax(3)=0;
  end
  axis(ax)
  hold off
  setappdata(figH,'axesH',gca);
  GraphUtils.NewZoomAndPan(figH);
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
