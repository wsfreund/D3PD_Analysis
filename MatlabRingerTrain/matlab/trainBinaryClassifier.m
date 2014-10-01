function [trainedClassifier,trainInfo] = trainBinaryClassifier(...
    dataStruct,paramOpts)

% - Creation Date: Fri, 26 Sep 2014
% - Last Modified: Wed, 01 Oct 2014
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
  case {'svm-matlab','svm-matlab-rbf','svm-matlab-mlp',...
      'svm-matlab-polynomial'}
    % Builtin matlab SVM
      defParamOpts = struct(...
       'classifierStr','',...
       'kernel_function','',...
       'autoscale',false,...
       'boxconstraint',1,...
       'xValParam',[],...
       'kernelcachelimit',20e3,... % Needs at least 381 MB
       'kktviolationlevel',0,...
       'method','SMO',...
       'options',[],...
       'tolkkt',1e-4,...
       'debug',false,...
       'evalTime',true,...
       'useParallel','yes'...
       );
  case 'MMNN'
    defParamOpts = struct(...
     'classifierStr','',...
     'trainMethod','trainrp',...
     'xValParam',[],...
     'evalTime',true,...
     'debug',false,...
     'dataNormalize',false,...
     'epsilon',[.1 .2],...
     'C',[-.1 1]...
     );
  case 'MatchedFilter'
    defParamOpts = struct(...
     'classifierStr','',...
     'xValParam',[],...
     'evalTime',true,...
     'debug',false,...
     'whiteningMatrix',[],...
     'whiteningMean',[],...
     'implementation','deterministic',...
     'deterministicExtractionMethod','mean',...
     'N0',[],'percEnergy',.95...
     );

  case 'MMGDX'
    %defParamOpts = struct(...

  case 'libsvm'
    % http://www.csie.ntu.edu.tw/~cjlin/libsvm/
    % Since version 2.8, it implements an SMO-type algorithm proposed
    % in this paper: "Working set selection using second order
    % information for training SVM"
  case 'MSVMpack'
    % http://www.loria.fr/~lauer/MSVMpack/MSVMpack.html
  case 'svlab'
    % This one is the one from the book
  end

  paramOpts = scanparam(defParamOpts,paramOpts);

  switch paramOpts.classifierStr
  case {'ffnn-fastnet','ffnn','ffnn-matlab'}
  case {'svm-matlab','svm-matlab-rbf','svm-matlab-mlp',...
      'svm-matlab-polynomial'}
    switch paramOpts.method
    case 'SMO'
      defSMOOpts = statset('MaxIter',500000,'Display','iter');
      paramOpts.options = scanparam(defSMOOpts,paramOpts.options);
      if paramOpts.debug
        paramOpts.options.MaxIter = 500;
      end
    case 'QP'
      if paramOpts.debug
        defQuadOpts = optimoptions('quadprog',...
          'Algorithm','interior-point-convex','MaxIter',30);
      else
        defQuadOpts = optimoptions('quadprog',...
          'Algorithm','interior-point-convex','MaxIter',5000);
      end
      if ~isempty(paramOpts.options)
        Output.WARNING('D3PDAnalysis:trainBinaryClassifier',...
          ['Required to change quadratic programing options, '...
          'but it is not yet implemented. Using default options']);
      end
    otherwise
      Output.ERROR('D3PDAnalysis:trainBinaryClassifier:WrongInput',...
        'Matlab svm-train method unknown: %s',paramOpts.method)
    end
  end


  % Change default settings if input is 

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
        if strcmp('yes',paramOpts.useParallel)
          n_threads = str2double(getenv('OMP_NUM_THREADS'));
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
      % Matlab seems to ignore data if they are the same:
      if isfield(dataStruct,'useTstAsValidation') && ...
          dataStruct.useTstAsValidation
        trainInfo.tperf = tmpTrainInfo.vperf;
      else
        trainInfo.tperf = tmpTrainInfo.tperf;
      end
      trainInfo.plotTrainEvolution = @(varargin) plotNNFFMatlab(...
        trainInfo,varargin{:});

    end
    trainedClassifier.userdata.outputFun = @(in) sim(...
      trainedClassifier,in);
    trainInfo.crossValidationParam = 'Hidden Neuron Units';
  case {'svm-matlab','svm-matlab-rbf','svm-matlab-mlp',...
      'svm-matlab-polynomial'}

    % Check if it helps on performance:
    if paramOpts.useParallel
      % Prepare matlab pool
      if strcmp('yes',paramOpts.useParallel)
        n_threads = str2double(getenv('OMP_NUM_THREADS'));
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
    svmOpts = paramOpts;
    svmOpts = rmfield(svmOpts,'debug');
    svmOpts = rmfield(svmOpts,'useParallel');
    svmOpts = rmfield(svmOpts,'classifierStr');
    svmOpts = rmfield(svmOpts,'xValParam');
    svmOpts = rmfield(svmOpts,'evalTime');
    if ischar(svmOpts.kernel_function)
      switch svmOpts.kernel_function
      case 'polynomial'
        svmOpts.polyorder = dataStruct.xValParam(1);
        if numel(dataStruct.xValParam)>1
          svmOpts.boxconstraint = dataStruct.xValParam(2);
          trainInfo.crossValidationParam = 'poly\_order | for C';
        else
          trainInfo.crossValidationParam = sprintf(...
            'poly_order, C = %g',svmOpts.boxconstraint);
        end
        Output.INFO(['Training matlab-svm-polynomial with '...
          ' polyorder %g and C = %g'],svmOpts.polyorder,...
          svmOpts.boxconstraint);
      case 'rbf'
        svmOpts.rbf_sigma = dataStruct.xValParam(1);
        if numel(dataStruct.xValParam)>1
          svmOpts.boxconstraint = dataStruct.xValParam(2);
          trainInfo.crossValidationParam = 'rbf\_sigma | C';
        else
          trainInfo.crossValidationParam = sprintf(...
            'rbf_sigma, for C = %d',svmOpts.boxconstraint);
        end
        Output.INFO(['Training matlab-svm-rbf with '...
          ' rbf_sigma %g and C = %g'],svmOpts.rbf_sigma,...
          svmOpts.boxconstraint);
      case 'mlp'
        svmOpts.mlp_params = dataStruct.xValParam(1:2);
        if numel(dataStruct.xValParam>2)
          svmOpts.boxconstraint = dataStruct.xValParam(3);
          trainInfo.crossValidationParam = ...
            'W_{MLP,Kernel} | b_{MLP,Kernel} | C';
        else
          trainInfo.crossValidationParam = sprintf(...
            'W_{MLP,Kernel} | b_{MLP,Kernel}, for C = %g',...
              svmOpts.boxconstraint);
        end
        Output.INFO(['Training matlab-svm-mlp with '...
          ' weigth %g, bias %g and C = %g'],svmOpts.mlp_params(1),...
          svmOpts.mlp_params(2),svmOpts.boxconstraint);
      end
    else
      Output.ERROR('Annonymous function kernels not supported');
    end
    cellArgs = [fieldnames(svmOpts)';struct2cell(svmOpts)'];
    if paramOpts.evalTime
      tic;
    end
    %while (true)
    %  try
        trainedClassifier = svmtrain(...
          [...
            dataStruct.sgn(:,trnSgnClusterInd) ...
            dataStruct.bkg(:,trnBkgClusterInd)...
          ]',...
          [...
            ones(1,numel(trnSgnClusterInd)) ...
            -ones(1,numel(trnBkgClusterInd)) ...
          ]',cellArgs{:});
    %    break;
    %  catch 
    %  end
    %end
    if paramOpts.evalTime
      trainInfo.trainTime = toc;
    end
    % TODO Epochs, and SVO, QP options
    trainedClassifier.userdata.outputFun = @(in) Output.ERROR(...
      'outputFun is not supported for svm-matlab for not.');
    trainedClassifier.userdata.labelFun = @(in) svmclassify(...
      trainedClassifier,in')';
  case 'MMNN'
    paramOpts.C(1) = dataStruct.xValParam(1);
    if numel(dataStruct.xValParam)>1
      paramOpts.epsilon(1) = dataStruct.xValParam(2);
      trainInfo.crossValidationParam = 'C1 | epsilon';
    else
      trainInfo.crossValidationParam = ...
        sprintf('C1, for epsilon = %g',paramOpts.epsilon(1));
    end
    if paramOpts.evalTime
      tic;
    end
    cellArgs = [fieldnames(paramOpts)';struct2cell(paramOpts)'];
    trainedClassifier = MMNN('trainData',...
      {...
        dataStruct.sgn(:,trnSgnClusterInd)... % First bkg to make it
        ...% have -1 output
        dataStruct.bkg(:,trnBkgClusterInd),... % Then signal, +1
      },...
      cellArgs{:});
    if paramOpts.evalTime
      trainInfo.trainTime = toc;
    end
      
    %trainedClassifier.userdata.outputFun = @(in) ...
    %  trainedClassifier.getOutputLayerZ(in);
    trainedClassifier.userdata.outputFun = @(in) Output.ERROR(...
      'outputFun is not supported for svm-matlab for not.');
    trainedClassifier.userdata.labelFun = @(in) ...
      trainedClassifier.NNMM_classify(in);
  case 'MatchedFilter'
    % TODO Preparate parameters for the matched filter, only for the
    % stochastic case:
    switch paramOpts.implementation
    case 'deterministic'
      trainInfo.crossValidationParam = ...
        ['Deterministic approximation method'];
    case 'stochastic'
      if numel(dataStruct.xValParam)==1 && ...
          ischar(dataStruct.xValParam)
        trainInfo.crossValidationParam = 'Stochastic method';
      end
      paramOpts.N0 = dataStruct.(1);
      trainInfo.crossValidationParam = 'N0';
      if numel(dataStruct.xValParam)>1
        paramOpts.percEnergy = dataStruct.xValParam(2);
      end
    end
    if paramOpts.evalTime
      tic;
    end
    trainedClassifier = MatchedFilterTrain(...
      dataStruct.sgn(:,trnSgnClusterInd),...
      dataStruct.bkg(:,trnBkgClusterInd),...
      paramOpts);
    if paramOpts.evalTime
      trainInfo.trainTime = toc;
    end
    trainedClassifier.userdata.outputFun = @(in) ...
      MatchedFilterPropagate(trainedClassifier,in);
  case 'MMGDX'
    if paramOpts.evalTime
      tic;
    end
    [trainedClassifier.Nor,...
      trainedClassifier.W1,...
      trainedClassifier.W2,...
      trainedClassifier.b1,...
      trainedClassifier.b2,...
      trainInfo.J,...
      trainInfo.time,...
      trainedClassifier.flag] = ...
      train_MMGDX(...
      [...
        dataStruct.sgn(:,trnSgnClusterInd) ...
        dataStruct.bkg(:,trnBkgClusterInd)...
      ]',...
      [...
        ones(1,numel(trnSgnClusterInd)) ...
        -ones(1,numel(trnBkgClusterInd)) ...
      ]',dataStruct.xValParam);
    if paramOpts.evalTime
      trainInfo.trainTime = toc;
    end

    trainedClassifier.userdata.outputFun = @(in) ...
      sim_MMGDX(...
      trainedClassifier.Nor,...
      trainedClassifier.W1,...
      trainedClassifier.W2,...
      trainedClassifier.b1,...
      trainedClassifier.b2,...
      in);


    keyboard
  case 'libsvm'
  end


end

function lineH = plotNNFFMatlab(trainInfo,varargin)
  if numel(varargin)<3
    varargin{3} = 'epoch';
    if numel(varargin)<2
      varargin{2} = gca;
      if numel(varargin)<1
        varargin{1} = 2;
      end
    end
  end
  plotStyle = varargin{1};
  axesH = varargin{2};
  xField = varargin{3};

  trnColor = [0.0706    0.4078    0.7020];
  valColor = [1    0    0];
  tstColor = [0   .8    0];

  if strcmp(varargin{3},'epoch')
    trainInfo.epoch = 1:numel(trainInfo.perf);
  end

  lineH = plot(axesH,trainInfo.(xField),trainInfo.perf);%,...
    %trainInfo.(xField),trainInfo.vperf);%,...
    %trainInfo.(xField),trainInfo.tperf);

  for k=1:numel(lineH)
    switch k
    case 1
      color = trnColor;
    case 2
      color = valColor;
    case 3
      color = tstColor;
    end
    switch plotStyle
    case 0
      set(lineH(k),'Color',GraphUtils.fadeColor(...
        color),'LineStyle','--');
    case 1
      set(lineH(k),'Color',GraphUtils.fadeColor(color));
    case 2
      set(lineH(k),'Color',color);
      set(lineH(k),'LineWidth',2,'LineStyle','--');
    case 3
      set(lineH(k),'Color',color);
      set(lineH(k),'LineWidth',4);
    otherwise
      Output.ERROR('D3PDAnalysis:trainedClassifier:plotNNFFMatlab',...
        'Unknown input plotStyle. It must be either 0, 1 or 2.');
    end
  end

end
