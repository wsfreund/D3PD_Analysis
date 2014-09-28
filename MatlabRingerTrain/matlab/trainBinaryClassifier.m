function [trainedClassifier,trainInfo] = trainBinaryClassifier(...
    dataStruct,paramOpts)

% - Creation Date: Fri, 26 Sep 2014
% - Last Modified: Sun, 28 Sep 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  switch paramOpts.classifierStr
  case {'ffnn-fastnet','ffnn','ffnn-matlab'}
    defParamOpts = struct(...
     'classifierStr','',...
     'trainMethod','trainrp',...
     'xValParam',[],...
     'epochs',10000,...
     'max_fail',50,...
     'show',25,...
     'goal',0,...
     'min_grad',0,...
     'time',Inf,...
     'showWindow',false,...
     'showCommandLine',true,...
     'useParallel','yes',...
     'evalTime',true,...
     'debug',false...
     );
  case 'libsvm'
    % http://www.csie.ntu.edu.tw/~cjlin/libsvm/
    % Since version 2.8, it implements an SMO-type algorithm proposed
    % in this paper:  Working set selection using second order
    % information for training SVM
    
  case 'svm-matlab'
    % Builtin matlab SVM
  case 'MSVMpack'
    % http://www.loria.fr/~lauer/MSVMpack/MSVMpack.html
  case 'svlab'
    % This one is the one from the book
  end


  paramOpts = scanparam(defParamOpts,paramOpts);

  trnSgnClusterInd = create_cluster(...
    dataStruct.sgn_cl_size,dataStruct.sgn_trn_clusters);
  trnBkgClusterInd = create_cluster(...
    dataStruct.bkg_cl_size,dataStruct.bkg_trn_clusters);
  valSgnClusterInd = create_cluster(...
    dataStruct.sgn_cl_size,dataStruct.sgn_val_clusters);
  valBkgClusterInd = create_cluster(...
    dataStruct.bkg_cl_size,dataStruct.bkg_val_clusters);
  tstSgnClusterInd = create_cluster(...
    dataStruct.sgn_cl_size,dataStruct.sgn_tst_clusters);
  tstBkgClusterInd = create_cluster(...
    dataStruct.bkg_cl_size,dataStruct.bkg_tst_clusters);

  sgn_total_size = size(dataStruct.sgn,2);
  sgnTest_total_size = size(dataStruct.testSgnData,2);
  bkg_total_size = size(dataStruct.bkg,2);
  bkgTest_total_size = size(dataStruct.testBkgData,2);

  switch paramOpts.classifierStr
  case {'ffnn-fastnet','ffnn','ffnn-matlab'}
    if ~isempty(strfind('fastnet',paramOpts.classifierStr))
      untrainedClassifier = newff2(...
        {...
          dataStruct.sgn(:,trnSgnClusterInd)...
            ,...
          dataStruct.bkg(:,trnBkgClusterInd)...
        },...
        {...
          ones(1,numel(trnSgnClusterInd)),...
          -ones(1,numel(trnBkgClusterInd))...
        },...
        paramOpts.xValParam,{'tansig' 'tansig'},... 
        paramOpts.trainMethod);
      untrainedClassifier.trainParam.useSP = true;
      % Set batch size as minimum size from both training parameters:
      untrainedClassifier.trainParam.batchSize = ...
        min([...
          numel(trnSgnClusterInd)...
          numel(trnBkgClusterInd)...
        ]);
    else
      fullData = [...
        dataStruct.sgn...
        dataStruct.testSgnData,...
        dataStruct.bkg...
        dataStruct.testBkgData...
      ];
      targetData = [...
        ones(1,sgn_total_size + sgnTest_total_size),...
        -ones(1,bkg_total_size + bkgTest_total_size)...
      ];
      untrainedClassifier = newff(fullData,targetData,...
        paramOpts.xValParam,{'tansig','tansig'},...
        paramOpts.trainMethod,'learngd','mse',...
        {'fixunknowns','removeconstantrows'},...
        {'removeconstantrows'},'divideind'...
      );
      untrainedClassifier.divideParam.trainInd = [...
          trnSgnClusterInd, ...
          (sgn_total_size + sgnTest_total_size + ...
          trnBkgClusterInd)];
      if isempty(dataStruct.testSgnData)
        untrainedClassifier.divideParam.testInd = [...
          tstSgnClusterInd,  ...
          (sgn_total_size + sgnTest_total_size + ...
          tstBkgClusterInd)];
      else
        untrainedClassifier.divideParam.testInd = ...
          [sgn_total_size + 1:...
            ...
            sgn_total_size + ...
            sgnTest_total_size,...
            ...
            sgn_total_size + ...
            sgnTest_total_size + ...
            bkg_total_size + 1:...
            ...
            sgn_total_size + ...
            sgnTest_total_size + ...
            bkg_total_size + ...
            bkgTest_total_size]; 
      end
      if isfield(dataStruct,'useTstAsValidation') && ...
          dataStruct.useTstAsValidation
        untrainedClassifier.divideParam.valInd = ...
          untrainedClassifier.divideParam.testInd;
      else
        untrainedClassifier.divideParam.valInd = [...
            valSgnClusterInd,  ...
            (sgn_total_size + sgnTest_total_size + ...
            valBkgClusterInd)];
      end
    end

    untrainedClassifier.trainParam.epochs   = paramOpts.epochs;
    untrainedClassifier.trainParam.max_fail = paramOpts.max_fail;
    untrainedClassifier.trainParam.show     = paramOpts.show;
    untrainedClassifier.trainParam.goal     = paramOpts.goal;
    untrainedClassifier.trainParam.min_grad = paramOpts.min_grad;
    untrainedClassifier.trainParam.time     = paramOpts.time;
    untrainedClassifier.trainParam.showWindow = paramOpts.showWindow;
    untrainedClassifier.trainParam.showCommandLine = ...
      paramOpts.showCommandLine;

    if paramOpts.debug
      untrainedClassifier.trainParam.epochs = 10;
    end

    if ~isempty(strfind('fastnet',paramOpts.classifierStr))
      trnCell = {dataStruct.sgn(:,trnSgnClusterInd)...
        dataStruct.bkg(:,trnBkgClusterInd)};
      tstCell = {[dataStruct.sgn(:,tstSgnClusterInd),...
        dataStruct.testSgnData],...
        [dataStruct.bkg(:,tstBkgClusterInd)...
        dataStruct.testBkgData]};
      if isfield(dataStruct,'useTstAsValidation') && ...
          dataStruct.useTstAsValidation
        valCell = tstCell;
      else
        valCell = {dataStruct.sgn(:,valSgnClusterInd),...
          dataStruct.bkg(:,valBkgClusterInd)};
      end
      if paramOpts.evalTime
        tic
      end
      [trainedClassifier,trainInfo] = ntrain(untrainedClassifier,...
        trnCell,valCell,tstCell);
      if paramOpts.evalTime
        trainInfo.trainTime = toc;
      end
    else
      if paramOpts.useParallel
        % Prepare matlab pool
        if strcmp('Yes',paramOpts.useParallel)
          n_threads = str2double(getenv('OMP_NUM_THREADS'))
          if isempty(n_threads) || ~isfinite(n_threads)
            paramOpts.useParallel = 'no';
          else
            isOpen = matlabpool('size');
            if isOpen ~= n_threads
              set(findResource(),'ClusterSize',n_threads)
              matlabpool('open',n_threads)
            end
          end
        end
      end

      if paramOpts.evalTime
        tic
      end
      [tmpClassifier,tmpTrainInfo] = train(untrainedClassifier,...
        fullData,targetData,'useParallel',paramOpts.useParallel);
      if paramOpts.evalTime
        trainInfo.trainTime = toc;
      end

      trainedClassifier = untrainedClassifier;
      trainedClassifier.LW = tmpClassifier.LW;
      trainedClassifier.IW = tmpClassifier.IW;
      trainedClassifier.b  = tmpClassifier.b;

      % Reduce data size on disk:
      trainedClassifier.divideParam.trainInd = [];
      trainedClassifier.divideParam.valInd = [];
      trainedClassifier.divideParam.testInd = [];

      % Keep only desired information:
      trainInfo.time = tmpTrainInfo.time;
      trainInfo.perf = tmpTrainInfo.perf;
      trainInfo.vperf = tmpTrainInfo.vperf;
      trainInfo.tperf = tmpTrainInfo.tperf;

    end
    trainedClassifier.userdata.outputFun = @(in) sim(...
      trainedClassifier,in);
    trainInfo.crossValidationParam = 'Hidden Neuron Units';
  case 'libsvm'
  end


end
