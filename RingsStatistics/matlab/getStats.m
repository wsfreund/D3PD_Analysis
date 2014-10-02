function [stats,data,handles]=getStats(varargin)
%
% TODO Help 
%

% - Creation Date: Tue, 19 Aug 2014
% - Last Modified: Thu, 02 Oct 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  defopts = struct('truth_type',11,'truth_mothertype',23,...
    'trnSgnIsEM_mask',966493,'trnBkgIsEM_mask',93,...
    'debug',false,'getStatsWrt','truth',...
    'sgnPath','~/Documents/Doutorado/CERN/D3PD/data/pileup_phase1/Zee_mc12_14TeV_d3pd_e1564_s1682_s1691_r4710_v17.mat',...
    'bkgPath','~/Documents/Doutorado/CERN/D3PD/data/pileup_phase1/JF17_mc12_14TeV_d3pd_e1313_s1682_s1691_r4710_v17.mat',...
    'sgn',[],'bkgFromSgn',[],'bkg',[],...
    'layerColors',[...
      GraphUtils.colorGradient(...
      [0 0 0],[0.170588 0.55784 0.90196],4,'Smoothing','on',...
      'SmoothThres',0.2);...
      GraphUtils.colorGradient(...
      [0 0 0],[.95 .3 .3],3,'Smoothing','on','SmoothThres',0.2)],...
    ...
    'runForNEvents',Inf,...
    'removeOutOfBound',false,...
    ...
    'histBoundMethod','auto','nBins',60,...
    'histPercentage',.99,'forceLowerBounds',true, ...
    'onlyForSgn',false,'chi2NBins',60,...
    ...
    'drawMeanMedianMode',true,...%true,...
    'drawRMSSkewnessKurt',true,...%true,...
    'drawCorrelationMatrix',true,...%true,...
    'doCrossDataCorrelations',false,...
    'doNonLinearCorrelations',false,...
    'drawKLDiv',false,...
    'drawHistGrid',true,...%true,...
    ...
    'doFit',false,'doFitRings',true,...
    'test_significance',0.05,'mle_confidence',.95,...
    'dist2test',{{'Gaussian','Lognormal','Laplace','Beta',...
    'Rayleigh','Gamma','Weibull','Exponential','Maxwell',...
    'Cauchy','BetaPrime','GenNormal_v1','SkewedNormal'}},...
    ...%'SkewedLaplace'}},...
    'drawOneByOneFit',false,...
    'drawEmpiricalData',true,...
    'drawBestFit',false,...
    'nLayerRings',[8 64 8 8 4 4 4],...
    'layerLabels',{{'PS','EM1','EM2','EM3',...
    'HAD1','HAD2','HAD3'}},...
    ...
    'outputFolder',[pwd filesep 'images'],...
    'savePlots',true,...
    ...
    'jobToDo',{{'part1','part2'}},...
    'part1_stat',[]...
    );

  if nargin>1
    opts = struct(varargin{:});
  elseif nargin==1
    opts = varargin{1};
  else
    opts = struct; 
  end

  opts = scanparam(defopts,opts);

  doPart1 = true;
  if ~any(strcmp(opts.jobToDo,'part1')) 
    if isempty(opts.part1_stat)
      Output.ERROR(['If you request to run only part2, you need to'...
        ' pass the part1 stats through the part1_stat property.']);
    end
    doPart1 = false;
  end

  doPart2 = true;
  if ~any(strcmp(opts.jobToDo,'part2')) 
    doPart2 = false;
  end

  if ~doPart1 && ~doPart2
    Output.ERROR('There is nothing defined to do on opts.jobToDo');
  end

  if opts.savePlots && ~exist(opts.outputFolder,'dir')
    mkdir(opts.outputFolder);
  end


  if ~iscell(opts.dist2test)
    opts.dist2test = {opts.dist2test};
  end

  if opts.debug && numel(opts.dist2test)>5
    opts.dist2test = opts.dist2test(1:5);
  end

  if ~isempty(opts.sgn)
    sgn = opts.sgn;
  end
  if ~isempty(opts.bkgFromSgn)
    bkgFromSgn = opts.bkgFromSgn;
  end
  if ~isempty(opts.bkg)
    bkg = opts.bkg;
  end


  % Check if it is possible to load debug data
  if (~exist('sgn','var') || ~exist('bkg','var') ...
      || ~exist('bkgFromSgn','var'))
    if opts.debug && exist(...
        '~/Documents/Doutorado/CERN/D3PD/data/pileup_phase1/debug.mat',...
        'file')
      load('~/Documents/Doutorado/CERN/D3PD/data/pileup_phase1/debug')
    else
      if ~opts.onlyForSgn
        % FIXME HACK FOR SEIXAS, CHANGE IT BACK TO OLD VALUE:
        %[sgn,bkgFromSgn,bkg] = extractDataFrom(opts);
        sgn = [];
        bkg = [];
        bkgFromSgn = [];
        load ~/Documents/Doutorado/Materias/Det_Sinais/trab2/smallData/pedestal_FixedSeed_NoCellExtraInfo.d3pd.mat

        %eta=-2.5:5/(200-1):2.5;
        %phi=0:2*pi/(256-1):2*pi;
        %[meshEta,meshPhi]=meshgrid(eta,phi);
        %whiteFigure(true);
        %cEvt=1;
        %n=hist3([pedestal.el_cl_eta0Calo(pedestal.el_evtNum==cEvt)',pedestal.el_cl_phi0Calo(pedestal.el_evtNum==cEvt)'],{eta phi});
        %spy(n)
        %xlabel('\eta')
        %ylabel('\phi')
        %title('Seed generated grid, EvtNum = 1')
        %localFigPath = [opts.outputFolder filesep 'seedGridGenEvt1'];
        %epswrite(double(gcf),[localFigPath '.eps'],'Size','Screen')
        %saveas(gcf,localFigPath,'png')
        %cEvt=2;
        %n=hist3([pedestal.el_cl_eta0Calo(pedestal.el_evtNum==cEvt)',pedestal.el_cl_phi0Calo(pedestal.el_evtNum==cEvt)'],{eta phi});
        %spy(n)
        %xlabel('\eta')
        %ylabel('\phi')
        %title('Seed generated grid, EvtNum = 2')
        %localFigPath = [opts.outputFolder filesep 'seedGridGenEvt2'];
        %epswrite(double(gcf),[localFigPath '.eps'],'Size','Screen')
        %saveas(gcf,localFigPath,'png')
        %localFigPath = [opts.outputFolder filesep 'reducedSetEvt'];
        %n=hist3([pedestal.el_cl_eta0Calo',pedestal.el_cl_phi0Calo'],{eta phi});
        %pcolor(meshEta,meshPhi,n')
        %xlabel('\eta')
        %ylabel('\phi')
        %title('Seed generated grid (for all reduced set events)')
        %colorbar
        %localFigPath = [opts.outputFolder filesep 'seedGridGenAllReducedSetEvts'];
        %epswrite(double(gcf),[localFigPath '.eps'],'Size','Screen')
        %saveas(gcf,localFigPath,'png')

        basePath = '/Users/wsfreund/Documents/Doutorado/Materias/Det_Sinais/trab2/smallData/';
        whiteningFile = [basePath 'whiteningNoiseData.mat'];

        eT = pedestal.el_E./cosh(pedestal.el_eta);
        selectionMsk = sum(pedestal.el_rings_NCells==0)<30 & ...
          abs(eT)<800;
        pedestal.el_rings_E = pedestal.el_rings_E(:,...
          selectionMsk);
        pedestal.el_rings_NCells = pedestal.el_rings_NCells(:,...
          selectionMsk);

        halfData = round(size(pedestal.el_rings_E,2)/2)

        [whiteningMatrix,~,lambdasquare,~,explained,whiteningMean] = ...
          pca(pedestal.el_rings_E(:,1:halfData)');

        whiteningMatrix = whiteningMatrix';
        whiteningMean = whiteningMean';
        whiteningScale = 1./sqrt(lambdasquare);


        %load(whiteningFile)

        pedestalTrain.el_rings_E = bsxfun(@times,...
          whiteningMatrix*bsxfun(...
            @minus,pedestal.el_rings_E(:,1:halfData),whiteningMean),...
            whiteningScale);
        pedestalTest.el_rings_E = bsxfun(@times,...
          whiteningMatrix*bsxfun(...
            @minus,pedestal.el_rings_E(:,halfData+1:end),whiteningMean),...
            whiteningScale);
        pedestal.el_rings_E = pedestal.el_rings_E;
        pedestal.el_rings_NCells = pedestal.el_rings_NCells;
      else
        sgn = extractDataFrom(opts);
      end
    end
  end

  % FIXME HACK FOR SEIXAS, CHANGE IT BACK TO OLD VALUE:
  if ~opts.debug && ~opts.onlyForSgn
    %data = [sgn bkgFromSgn bkg] %pedestal pedestalTrain pedestalTest};
    data = {sgn bkgFromSgn bkg pedestal pedestalTrain pedestalTest};
  else
    data = sgn;
  end

  if ~doPart1
    stats = opts.part1_stat;
    for cIdx = 1:numel(data)
      if isfield(stats(cIdx),'runForNEvents')
        opts.runForNEvents = min(opts.runForNEvents,...
          stats(cIdx).runForNEvents);
      end
    end
  else
    stats = struct('dMean',cell(1,numel(data)));
  end

  % FIXME Uncomment this
  %for cIdx = 1:numel(data)
  %  if size(data(cIdx).el_rings_E,2)>opts.runForNEvents
  %    fieldNames = fieldnames(data(cIdx))';
  %    for field = fieldNames
  %      name = field{1};
  %      data(cIdx).(name) = data(cIdx).(name)(:,1:opts.runForNEvents);
  %      stats(cIdx).runForNEvents = opts.runForNEvents;
  %    end
  %  end
  %end

  handles = struct('figH_histGrid',cell(1,numel(data)));
  layerCode = {'ps' 'em1' 'em2' 'em3' 'had1' 'had2' 'had3'};

  for cIdx = 1:numel(data)

    if iscell(data(cIdx))
      cData = data{cIdx};
    else
      cData = data(cIdx);
    end

    if isempty(cData)
      continue;
    end

    if isempty(cData.el_rings_E)
      continue;
    end

    % FIXME this should be on part 1:
    switch cIdx
    case 1
      stats(cIdx).dataLabel = 'Zee-Whitened';
      stats(cIdx).color = [0.070588 0.40784 0.70196];
    case 2
      stats(cIdx).dataLabel = 'BkgFromZee-Whitened';
      stats(cIdx).color = [.8 .8 .0];
      continue
    case 3
      stats(cIdx).dataLabel = 'JF17-Whitened';
      stats(cIdx).color = [.5 0 0];
    case 4
      stats(cIdx).dataLabel = 'Pedestal';
      stats(cIdx).color = [.5 0 0];
      % continue
    case 5
      stats(cIdx).dataLabel = 'Pedestal-Whitened-Train';
      stats(cIdx).color = [.8 .8 0];
    case 6
      stats(cIdx).dataLabel = 'Pedestal-Whitened-Test';
      stats(cIdx).color = [0.070588 0.40784 0.70196];
    end

    if doPart1
      Output.INFO('Starting analysis for %s (%d)',...
        stats(cIdx).dataLabel,size(cData.el_rings_E,2));

      % Get mean and standard deviation stats:
      Output.INFO('Getting simple moment data...');
      stats(cIdx).dMean = mean(cData.el_rings_E,2);
      stats(cIdx).dMedian = median(cData.el_rings_E,2);
      stats(cIdx).dStd = std(cData.el_rings_E,0,2);
      [stats(cIdx).nRings,stats(cIdx).nSamples]=size(cData.el_rings_E);
      if isfield(cData,'el_rings_NCells')
        zerosIdx = cData.el_rings_NCells==0;
      else
        zerosIdx = cData.el_rings_E==0;
      end
      stats(cIdx).dNonZeroesMean   = zeros(1,stats(cIdx).nRings);
      stats(cIdx).dNonZeroesMode   = zeros(1,stats(cIdx).nRings);
      stats(cIdx).dNonZeroesMedian = zeros(1,stats(cIdx).nRings);
      stats(cIdx).dNonZeroesStd    = zeros(1,stats(cIdx).nRings);
      for cRing = 1:stats(cIdx).nRings
        stats(cIdx).dNonZeroesMean(cRing) = mean(...
          cData.el_rings_E(cRing,~zerosIdx(cRing,:)),2);
        stats(cIdx).dNonZeroesMedian(cRing) = median(...
          cData.el_rings_E(cRing,~zerosIdx(cRing,:)),2);
        stats(cIdx).dNonZeroesStd(cRing) = std(...
          cData.el_rings_E(cRing,~zerosIdx(cRing,:)),0,2);
      end

      % Rings Energy stats:
      stats(cIdx).dMin = min(cData.el_rings_E,[],2);
      stats(cIdx).dMax = max(cData.el_rings_E,[],2);

      % Get bounds:
      Output.INFO('Getting bounds...');
      [stats(cIdx).lowerBounds,stats(cIdx).upperBounds,stats(cIdx).perc,...
        stats(cIdx).underflows,stats(cIdx).zeroCounts,stats(cIdx).overflows,...
        stats(cIdx).enBinsCenters,stats(cIdx).enBinsEdges,stats(cIdx).counts] = ...
        getDataBoundsAndBins(stats(cIdx),cData,opts);

      % Fill more specific bound information:
      for cLayer = 1:numel(layerCode)
        stats(cIdx).(sprintf('%s_bounds',layerCode{cLayer})) = ...
          getStatsInfoFor(...
          [stats(cIdx).lowerBounds;stats(cIdx).upperBounds]',...
          layerCode{cLayer},true);
      end

      if opts.doFit
        [stats(cIdx).fitParams,stats(cIdx).fitParamsCI,...
          stats(cIdx).ksgofRes,stats(cIdx).chi2gofRes,...
          stats(cIdx).counts_estimates] = ...
          fitPdf(stats(cIdx),cData,opts);
      end

      stats(cIdx).distTested = opts.dist2test;
    end

    
    % FIXME: This should be on part 1:
    stats(cIdx).dSkewness = skewness(cData.el_rings_E,1,2);
    stats(cIdx).dKurtsosis = kurtosis(cData.el_rings_E,1,2)-3;
    stats(cIdx).dNonZeroesSkewness = zeros(1,stats(cIdx).nRings);
    stats(cIdx).dNonZeroesKurtosis = zeros(1,stats(cIdx).nRings);
    if isfield(cData,'el_rings_NCells')
      zerosIdx = cData.el_rings_NCells==0;
    else
      zerosIdx = cData.el_rings_E==0;
    end
    for cRing = 1:stats(cIdx).nRings
      stats(cIdx).dNonZeroesSkewness(cRing) = skewness(...
        cData.el_rings_E(cRing,~zerosIdx(cRing,:)),1,2);
      stats(cIdx).dNonZeroesKurtosis(cRing) = kurtosis(...
        cData.el_rings_E(cRing,~zerosIdx(cRing,:)),1,2)-3;
    end
    stats(cIdx).dNoOutlierStd =  zeros(1,stats(cIdx).nRings);
    stats(cIdx).dNoOutlierSkewness =  zeros(1,stats(cIdx).nRings);
    stats(cIdx).dNoOutlierKurtsosis = zeros(1,stats(cIdx).nRings);
    stats(cIdx).dNoOutlierNonZeroesStd = zeros(1,stats(cIdx).nRings);
    stats(cIdx).dNoOutlierNonZeroesSkewness = zeros(1,stats(cIdx).nRings);
    stats(cIdx).dNoOutlierNonZeroesKurtosis = zeros(1,stats(cIdx).nRings);
    if isfield(cData,'el_rings_NCells')
      zerosIdx = cData.el_rings_NCells==0;
    else
      zerosIdx = cData.el_rings_E==0;
    end
    for cRing = 1:stats(cIdx).nRings
      goodIdx = cData.el_rings_E(cRing,:)>stats(cIdx).lowerBounds(cRing) & ...
        cData.el_rings_E(cRing,:)<stats(cIdx).upperBounds(cRing);
      stats(cIdx).dNoOutlierStd = std(...
        cData.el_rings_E(cRing,goodIdx),0,2);
      stats(cIdx).dNoOutlierSkewness = skewness(...
        cData.el_rings_E(cRing,goodIdx),1,2);
      stats(cIdx).dNoOutlierKurtsosis = kurtosis(...
        cData.el_rings_E(cRing,goodIdx),1,2)-3;
      stats(cIdx).dNoOutlierNonZeroesStd(cRing) = std(...
        cData.el_rings_E(cRing,~zerosIdx(cRing,:) & goodIdx),0,2);
      stats(cIdx).dNoOutlierNonZeroesSkewness(cRing) = skewness(...
        cData.el_rings_E(cRing,~zerosIdx(cRing,:) & goodIdx),1,2);
      stats(cIdx).dNoOutlierNonZeroesKurtosis(cRing) = kurtosis(...
        cData.el_rings_E(cRing,~zerosIdx(cRing,:) & goodIdx),1,2)-3;
    end

    if doPart2
      % TODO Eta stats:

      % TODO Phi stats:

      % TODO Et stats:

      % Get hist grid stats:
      Output.INFO('Creating hist stats...');
      [stats(cIdx).dNonZeroesMode,...
        handles(cIdx).figH_histGrid,handles(cIdx).axesH_histGrid,...
        handles(cIdx).ringHistH,...
        handles(cIdx).ringEstH,...
        handles(cIdx).fitTextH]...
        = getHistGrid(stats(cIdx),opts);

       % Correlation plots:
      [stats(cIdx).linearCorrelations,...
        stats(cIdx).nonLinearCorrelations,...
        handles(cIdx).figH,handles(cIdx).figNonLinearH] = ...
        getCorrelations(cData,stats(cIdx),opts);
        

      % TODO KL-Div
      % [stats(cIdx).klDiv,handles(cIdx).figH_klDiv] = ...
      %   getKLDivergence(stats(cIdx),opts);
      % Comparative with Standard Egamma:
    end
  end

  % Comparative plots:
  if opts.drawMeanMedianMode
    [handles(cIdx).figH_meanMeadianMode,...
      handles(cIdx).axesH_meanMedianMode,...
      handles(cIdx).barH_meanMedianMode] = ...
      plotMeanMedianMode(stats,opts);
  end

  if opts.drawRMSSkewnessKurt
    [handles(cIdx).figH_RMSSkewnessKurt,...
      handles(cIdx).axesH_RMSSkewnessKurt,...
      handles(cIdx).barH_RMSSkewnessKurt,...
      handles(cIdx).figH_RMSSkewnessKurt_NoOutlier,...
      handles(cIdx).axesH_RMSSkewnessKurt_NoOutlier,...
      handles(cIdx).barH_RMSSkewnessKurt_NoOutlier,...
      ] = ...
      plotRMSSkewnessKurt(stats,opts)
  end


end

function [sgn,bkgFromSgn,bkg]=extractDataFrom(opts)

  if ~exist(opts.sgnPath,'file')
    opts.sgnPath = ...
      '~/CERN/data/pileup_phase1/Zee_mc12_14TeV_d3pd_e1564_s1682_s1691_r4710_v17.mat';
  end
  sgnData = load(opts.sgnPath);

  k = fieldnames(sgnData);
  if numel(k)==1
    Zee = sgnData.(k{1});
  else
    Output.ERROR('D3PD_Analysis:SgnNotAvailable',...
      'Signal data is not available at path %s',sgnPath);
  end

  if ~opts.onlyForSgn
    if ~exist(opts.bkgPath,'file')
      opts.bkgPath = ...
        '~/CERN/data/pileup_phase1/JF17_mc12_14TeV_d3pd_e1313_s1682_s1691_r4710_v17.mat';
    end
    bkgData = load(opts.bkgPath);
    k = fieldnames(bkgData);
    if numel(k)==1
      JF17 = bkgData.(k{1});
    else
      Output.ERROR('D3PD_Analysis:BkgNotAvailable',...
        'Signal data is not available at path %s',bkgPath);
    end
  end

  clear sgnData bkgData

  if exist('Zee','var')
    % Get signal from electron dataset:
    if strcmp(opts.getStatsWrt,'truth')
      sgnMsk = abs(Zee.el_truth_type)==opts.truth_type & ...
        Zee.el_truth_mothertype==opts.truth_mothertype;
    elseif strcmp(opts.getStatsWrt,'standard')
      sgnMsk = Zee.el_rings_E(:,~(bitand(Zee.el_isEM,opts.trnSgnIsEM_mask)));
      bkgFromSgnMsk = Zee.el_rings_E(:,bitand(Zee.el_isEM,opts.trnBkgIsEM_mask));
    end

    fieldNames = fieldnames(Zee)';

    for field = fieldNames
      name = field{1};
      sgn.(name) = Zee.(name)(:,sgnMsk);
      if ~exist('bkgFromSgnMsk','var')
        bkgFromSgn.(name) = Zee.(name)(:,~sgnMsk);
      else
        bkgFromSgn.(name) = Zee.(name)(:,bkgFromSgnMsk);
      end
    end
  else
    Output.ERROR('D3PD_Analysis:RingsStatistics:SgnNotAvailable',...
      'Signal data is not available at path %s',sgnPath);
  end

  % Get information from jet data:
  if ~opts.onlyForSgn
    if exist('JF17','var')
      fieldNames = fieldnames(JF17)';
      if strcmp(opts.getStatsWrt,'standard')
        bkgFromSgnMsk = JF17.el_rings_E(:,...
          bitand(Zee.el_isEM,opts.trnBkgIsEM_mask));
      end
      for field = fieldNames
        name = field{1};
        if exist('bkgFromSgnMsk','var')
          bkg.(name) = JF17.(name)(:,bkgFromSgnMsk);
        else
          bkg.(name) = JF17.(name);
        end
      end
    else
      Output.ERROR('D3PD_Analysis:RingsStatistics:BkgNotAvailable',...
        'Backgroung data is not available at path %s',bkgPath);
    end
  end

  % If requested debug, run only for 1000 events:
  if opts.debug && size(sgn.el_rings_E,2)>1000
    fieldNames = fieldnames(sgn)';
    for field = fieldNames
      name = field{1};
      sgn.(name) = sgn.(name)(:,1:1000);
    end
  end
  if opts.debug && size(bkgFromSgn.el_rings_E,2)>1000
    fieldNames = fieldnames(bkgFromSgn)';
    for field = fieldNames
      name = field{1};
      bkgFromSgn.(name) = bkgFromSgn.(name)(:,1:1000);
    end
  end
  if ~opts.onlyForSgn
    if opts.debug && size(bkg.el_rings_E,2)>1000
      fieldNames = fieldnames(bkg)';
      for field = fieldNames
        name = field{1};
        bkg.(name) = bkg.(name)(:,1:1000);
      end
    end
  end

end

function [lowerBounds,upperBounds,perc,underflows,zeroCounts,...
    overflows,enBinsCenters,enBinsEdges,counts] = ...
    getDataBoundsAndBins(cStat,cData,opts)

  dMin = cStat.dMin;
  dMax = cStat.dMax;

  nLayerRings = opts.nLayerRings;
  layerEdges = [1 (cumsum(nLayerRings(1:end-1))+1)];

  nBins = opts.nBins;
  enBinsCenters = zeros(cStat.nRings,nBins);
  enBinsEdges = zeros(cStat.nRings,nBins+1);
  counts = zeros(cStat.nRings,nBins);

  lowerBounds = zeros(1,cStat.nRings);
  upperBounds = zeros(1,cStat.nRings);
  perc = zeros(1,cStat.nRings);
  underflows = zeros(1,cStat.nRings);
  overflows = zeros(1,cStat.nRings);
  zeroCounts = zeros(1,cStat.nRings);    
  dataSize = size(cData.el_rings_E,2);

  switch opts.histBoundMethod
  case 'auto'
    bounds = [2:10];
    for cRing = 1:cStat.nRings
      % Get non zero rings:
      if isfield(cData,'el_rings_NCells')
        rings = cData.el_rings_E(cRing,cData.el_rings_NCells(cRing,:)~=0);
      else
        rings = cData.el_rings_E(cRing,cData.el_rings_E(cRing,:)~=0);
      end
      nonZeroDataSize = size(rings,2);
      % Count number of null energy rings on this ring:
      zeroCounts(cRing) = (dataSize - nonZeroDataSize)/dataSize;

      % Check for lower bound:
      if ~opts.forceLowerBounds
        cMin = dMin(cRing);
        minPower10 = Utils.powerOfTenNumOrder(cMin,false);
        for cBound = bounds*10^minPower10
          if abs(cMin) < cBound
            if cMin < 0
              lowerBounds(cRing) = -cBound;
            else
              lowerBounds(cRing) = cBound;
            end
            break;
          end
        end
      else
        lowerBounds(cRing) = -500;
        while sum(rings<lowerBounds(cRing))/nonZeroDataSize ...
            > (1 - opts.histPercentage)/2
          lowerBounds(cRing) = lowerBounds(cRing) - 500;
        end
      end
      % Count number of underflows on this ring:
      underflows(cRing) = sum(...
        rings<lowerBounds(cRing))/nonZeroDataSize;

      % Define a good maximum value to use:
      cMax = dMax(cRing);
      maxPower10 = Utils.powerOfTenNumOrder(cMax,false);
      %Output.INFO('Before: maxPower10=%d for Ring %d',maxPower10,cRing);
      cPerc = 1 - underflows(cRing);
      while cPerc > opts.histPercentage
        if cMax - 10^(maxPower10-1) < .8*cMax
          maxPower10=maxPower10-1;
        end
        cMax = cMax - 10^(maxPower10-1);
        cPerc = (sum(rings<=cMax)/nonZeroDataSize - underflows(cRing));
      end
      %show = cPerc < opts.histPercentage-0.01;
      %if show
      %  Output.INFO('Before: cPerc:%f|cMax:%f for Ring %d',cPerc,cMax,cRing);
      %end
      %Check if percentage went to low:
      while cPerc < opts.histPercentage-0.001
        cMax = cMax + 10^(maxPower10-2);
        cPerc = (sum(rings<=cMax)/nonZeroDataSize - underflows(cRing));
      end
      %if show
      %  Output.INFO('After: cPerc:%f|cMax:%f for Ring %d',cPerc,cMax,cRing);
      %end
      maxPower10 = Utils.powerOfTenNumOrder(cMax,false);
      %Output.INFO('After: maxPower10=%d for Ring %d',maxPower10,cRing);

      % Now get its correspondent bound:
      for cBound = bounds*10^maxPower10
        if abs(cMax) < cBound
          if cMax < 0
            upperBounds(cRing) = -cBound; 
          else
            upperBounds(cRing) = cBound; 
          end
          break;
        end
      end

      % Make some corrections:
      if lowerBounds(cRing) < 0 && -lowerBounds(cRing)>upperBounds(cRing)
        lowerBounds(cRing) = -upperBounds(cRing);
      end
      if lowerBounds(cRing) < 0 ...
          && -lowerBounds(cRing)<upperBounds(cRing) ...
          && upperBounds(cRing)<=1000
        lowerBounds(cRing) = -upperBounds(cRing);
      end
      currentEdge = layerEdges(find(cRing>=layerEdges,1,'last'));
      prevIdx=(currentEdge-1)+find(...
        upperBounds(cRing)>upperBounds(currentEdge:cRing-1),1);
      if all(cRing~=layerEdges) && ~isempty(prevIdx) 
        upperBounds(prevIdx:cRing-1)=upperBounds(cRing);
        changeLowerBoundsMsk = false(1,cStat.nRings);
        changeLowerBoundsMsk(prevIdx:cRing-1) =  ...
          lowerBounds(prevIdx:cRing-1)<0 & ... 
          -lowerBounds(prevIdx:cRing-1)>upperBounds(prevIdx:cRing-1);
        lowerBounds(changeLowerBoundsMsk) = ...
          -upperBounds(changeLowerBoundsMsk);
        changeLowerBoundsMsk(prevIdx:cRing-1) =  ...
          lowerBounds(prevIdx:cRing-1)<0 & ... 
          -lowerBounds(prevIdx:cRing-1)<upperBounds(prevIdx:cRing-1) & ...
          upperBounds(cRing)<=1000;
        lowerBounds(changeLowerBoundsMsk) = ...
          -upperBounds(changeLowerBoundsMsk);
      end

      underflows(cRing) = sum(...
        rings<lowerBounds(cRing))/nonZeroDataSize;
      overflows(cRing) = sum(rings>upperBounds(cRing)) / nonZeroDataSize;
      perc(cRing) = 1. - underflows(cRing) - overflows(cRing);
      Output.INFO('Overflows:%f|%f Ring %d\n', (sum(rings>cMax) / ...
        nonZeroDataSize)*100,overflows(cRing)*100,cRing);
    end
    %
  case 'fixed'
    % TODO:
  end

  % Now compute the bins:
  for cRing = 1:cStat.nRings
    % Get non zero rings:
    rings = cData.el_rings_E(cRing,cData.el_rings_E(cRing,:)~=0);
    % Compute bins:
    cLB = lowerBounds(cRing);
    cUB = upperBounds(cRing);
    h = (cUB-cLB)/nBins;
    enBinsEdges(cRing,:) = cLB:h:cUB;
    enBinsCenters(cRing,:) = cLB+h/2:h:cUB-h/2;
    % Force histogram to have required bounderies from cStat:
    counts(cRing,:)=hist(rings,enBinsCenters(cRing,:));
    % Normalize counts:
    % counts(cRing,:) = counts(cRing,:)/cStat.nSamples;
  end
end

function [fitParams,fitParamsCI,ksgofRes,chi2gofRes,counts_estimates] = ...
    fitPdf(cStat,cData,opts)

  dist2test = opts.dist2test;

  % TODO: Implement half gaussian, half exponential;
  
  % dist2test = {'InvGauss'}; XXX InvGauss does not work! Do not use
  % it!

  %dist2test = opts.dist2test;
  nTests = numel(dist2test);
  nBins = opts.nBins;

  fitParams = cell(nTests,1);
  fitParamsCI = cell(nTests,cStat.nRings);
  for cDist = 1:nTests
    switch dist2test{cDist}
    case 'Gaussian' 
      % Gaussian has 2 free parameters (mu,sigma):
      fitParams{cDist} = zeros(cStat.nRings,2);
    case 'Beta'
      % Beta has 2 free parameters (a,b):
      fitParams{cDist} = zeros(cStat.nRings,2);
    case {'Gamma','Erlang','Gamma (Erlang)'}
      % Gamma is Erlang when a \in intenger
      % Gamma has 2 free parameters (a: shape parameter,b:scale
      % parameter):
      fitParams{cDist} = zeros(cStat.nRings,2);
    case 'Laplace'
      % Non matlab default distribution:
      % mu and b:
      fitParams{cDist} = zeros(cStat.nRings,2);
    case 'InvGauss'
      % Has 2 free parameters (mu: scale parameter,
      % lambda: shape);
      fitParams{cDist} = zeros(cStat.nRings,2);
    case 'Lognormal'
      % Lognormal has 2 parameters (mu,sigma):
      fitParams{cDist} = zeros(cStat.nRings,2);
    case 'Rayleigh'
      % Rayleigh has 1 parameter (b, scale parameter):
      fitParams{cDist} = zeros(cStat.nRings,1);
    case 'Cauchy'
      % TODO Non-matlab default distribution
    case 'Weibull'
      % Weibull has 2 parameter (a: shape, b:scale)
      fitParams{cDist} = zeros(cStat.nRings,2);
    case 'Maxwell'
      % TODO Non-matlab default distribution
      fitParams{cDist} = zeros(cStat.nRings,1);
    case 'Exponential'
      % Exponential has 1 parameter (mu)
      fitParams{cDist} = zeros(cStat.nRings,1);
    case 'Uniform'
      % Uniform has 2 parameters (a lower min, b max lim):
      fitParams{cDist} = zeros(cStat.nRings,2);
    %case 'Gumbel'
    %  % Gumbel has 2 parameters (mu real, beta scale)
    %  fitParams{cDist} = zeros(cStat.nRings,2);
    case 'GenNormal_v1'
      % Generalized normal has 3 parameters (mu location, alpha scale,
      % beta shape):
      fitParams{cDist} = zeros(cStat.nRings,3);
    %case 'GenNormal_v2'
    %  % Generalized normal has 3 parameters (eps location, alpha scale,
    %  % kappa shape):
    %  fitParams{cDist} = zeros(cStat.nRings,3);
    case 'SkewedNormal'
      % Skewed normal has 3 parameters (eps location, omega scale,
      % alpha shape)
      fitParams{cDist} = zeros(cStat.nRings,3);
    case 'SkewedLaplace'
      % Skewed laplace has 3 parameters (eps location, sigma scale,
      % kappa shape)
      fitParams{cDist} = zeros(cStat.nRings,3);
    case 'BetaPrime'
      fitParams{cDist} = zeros(cStat.nRings,2);
    end

  end

  % Variables to keep track from the tests:
  ksgof_h = zeros(cStat.nRings,nTests);
  ksgof_p = zeros(cStat.nRings,nTests);
  ksgof_stat = zeros(cStat.nRings,nTests);
  ksgof_cv = zeros(cStat.nRings,nTests);
  chi2gof_hist_h = zeros(cStat.nRings,nTests);
  chi2gof_hist_p = zeros(cStat.nRings,nTests);
  chi2gof_hist_stat = struct('chi2stat',cell(cStat.nRings,nTests),...
    'df',cell(cStat.nRings,nTests),...
    'edges',cell(cStat.nRings,nTests),'O',cell(cStat.nRings,nTests),...
    'E',cell(cStat.nRings,nTests));
  chi2gof_h = zeros(cStat.nRings,nTests);
  chi2gof_p = zeros(cStat.nRings,nTests);
  chi2gof_stat = struct('chi2stat',cell(cStat.nRings,nTests),...
    'df',cell(cStat.nRings,nTests),...
    'edges',cell(cStat.nRings,nTests),'O',cell(cStat.nRings,nTests),...
    'E',cell(cStat.nRings,nTests));
  counts_estimates = repmat({zeros(cStat.nRings,nBins)},1,nTests);

  for cDist = 1:nTests
    distArgs = {};
    extraArgs = {};
    distType = '';
    cdfFun = @cdf;
    positiveSupportOnly = false;
    max1Support = false;
    switch dist2test{cDist}
    case 'Gaussian' 
      distType = 'Normal';
      distArgs = {'distribution',distType};
      extraArgs = {'start',[NaN NaN],'lower',[-Inf 0]};
    case 'Beta'
      distType = 'Beta';
      distArgs = {'distribution',distType};
      extraArgs = {'start',2,'lower',0};
      positiveSupportOnly = true;
      max1Support = true;
    case {'Gamma','Erlang','Gamma (Erlang)'}
      distType = 'Gamma';
      distArgs = {'distribution',distType};
      extraArgs = {'start',2,'lower',0};
      positiveSupportOnly = true;
    case 'Laplace'
      cdfFun = @(~,varargin) laplace_cdf(varargin{:});
      distArgs = {'pdf',@laplace_pdf,'cdf',@laplace_cdf};
      extraArgs = {'start',[NaN NaN],'lower',[-Inf 0]};
    case 'InvGauss'
      cdfFun = @(~,varargin) inverse_gauss_cdf(varargin{:});
      distArgs = {'pdf',@inverse_gauss_pdf,...
          'cdf',@inverse_gauss_cdf};
      extraArgs = {'start',[NaN NaN],'lower',[0 0]};
      positiveSupportOnly = true;
    case 'Lognormal'
      distType = 'Lognormal';
      distArgs = {'distribution',distType};
      extraArgs = {'start',[NaN NaN],'lower',[0 0]};
      positiveSupportOnly = true;
    case 'Rayleigh'
      distType = 'Rayleigh';
      distArgs = {'distribution',distType};
      extraArgs = {'start',1,'lower',0};
      positiveSupportOnly = true;
    case 'Cauchy'
      cdfFun = @(~,varargin) cauchy_cdf(varargin{:});
      distArgs = {'pdf',@cauchy_pdf,'cdf',@cauchy_cdf};
      extraArgs = {'start',[NaN NaN],'lower',[-Inf 0]};
    case 'Weibull'
      distType = 'Weibull';
      distArgs = {'distribution',distType};
      extraArgs = {'start',[1 1],'lower',[0 0]};
      positiveSupportOnly = true;
    case 'Maxwell'
      cdfFun = @(~,varargin) maxwell_cdf(varargin{:});
      distArgs = {'pdf',@maxwell_pdf,'cdf',@maxwell_cdf};
      extraArgs = {'start',1e4,'lower',0};
      positiveSupportOnly = true;
    case 'Exponential'
      distType = 'Exponential';
      distArgs = {'distribution',distType};
      extraArgs = {'start',1,'lower',0};
      positiveSupportOnly = true;
    case 'Uniform'
      distType = 'Uniform';
      distArgs = {'distribution',distType};
      extraArgs = {'start',[NaN NaN]};
    %case 'Gumbel'
    %  cdfFun = @(~,varargin) gumbel_cdf(varargin{:});
    %  distArgs = {'pdf',@gumbel_pdf,'cdf',@gumbel_cdf};
    %  extraArgs = {'start',[.3 1],'lower',[0 0]};
    %  positiveSupportOnly = true;
    %  max1Support = true;
    case 'GenNormal_v1'
      cdfFun = @(~,varargin) gennormal_v1_cdf(varargin{:});
      distArgs = {'pdf',@gennormal_v1_pdf,'cdf',@gennormal_v1_cdf};
      extraArgs = {'start',[NaN NaN 2],'lower',[-Inf 0 0]};
    %case 'GenNormal_v2'
    %  cdfFun = @(~,varargin) gennormal_v2_cdf(varargin{:});
    %  distArgs = {'pdf',@gennormal_v2_pdf,'cdf',@gennormal_v2_cdf};
    %  extraArgs = {'start',[NaN NaN 1],'lower',[-Inf 0 0]};
    case 'SkewedNormal'
      cdfFun = @(~,varargin) gauss_skewed_cdf(varargin{:});
      distArgs = {'pdf',@gauss_skewed_pdf,'cdf',@gauss_skewed_cdf};
      optimOpt = statset('mlecustom');
      optimOpt.MaxIter = 1000;
      extraArgs = {'start',[3 1 10],'lower',[0 0 -Inf],...
        'optimfun','fmincon','options',optimOpt};
    case 'SkewedLaplace'
      cdfFun = @(~,varargin) laplace_skewed_cdf(varargin{:});
      distArgs = {'pdf',@laplace_skewed_pdf,'cdf',...
        @laplace_skewed_cdf};
      optimOpt = statset('mlecustom');
      optimOpt.MaxIter = 1000;
      extraArgs = {'start',[3 1 10],'lower',[-Inf 0 -Inf],...
        'optimfun','fmincon','options',optimOpt};
    case 'BetaPrime'
      cdfFun = @(~,varargin) betaprime_cdf(varargin{:});
      distArgs = {'pdf',@betaprime_pdf,'cdf',@betaprime_cdf};
      extraArgs = {'start',[1 1],'lower',[0 0]};
      positiveSupportOnly = true;
      max1Support = true;
    end
    Output.INFO('Estimating for %s distribution...',dist2test{cDist});
    if opts.doFitRings
      for cRing = 1:cStat.nRings
        Output.INFO('Estimating Ring %d...',cRing);

        cLB = cStat.lowerBounds(cRing);
        cUB = cStat.upperBounds(cRing);

        % Get non zero rings:
        rings = unique(...
          cData.el_rings_E(cRing,cData.el_rings_E(cRing,:)~=0));
        if opts.removeOutOfBound
          rings = rings(rings>=cLB & rings <= cUB);
        end
        nSamples = numel(rings);

        deslocated_rings = rings;
        deslocate = 0;
        inv_max = 1;
        deslocated_edges = cStat.enBinsEdges(cRing,:);
        if positiveSupportOnly 
          if min(rings) < 0
            deslocate = -min(rings);
          end
          deslocated_rings = rings + deslocate;
          deslocated_edges = deslocated_edges + deslocate;
          if max1Support 
            if max(deslocated_rings>1)
              inv_max = 1/max(deslocated_rings);
            end
            deslocated_rings = deslocated_rings * inv_max;
            deslocated_edges = deslocated_edges * inv_max;
            idx_to_change = deslocated_rings>=1;
            deslocated_rings(idx_to_change)=1-eps;
            idx_to_change = deslocated_edges>=1;
            deslocated_edges(idx_to_change)=1-eps;
          end
          idx_to_change = deslocated_rings<=0;
          deslocated_rings(idx_to_change)=0+eps;
          idx_to_change = deslocated_edges<=0;
          deslocated_edges(idx_to_change)=0+eps;
        end

        % Change some specific distribution start point:
        switch dist2test{cDist}
        case {'Gaussian','Laplace','Cauchy'}
          extraArgs{2}(:) = [cStat.dMean(cRing);cStat.dStd(cRing)];
        case {'GenNormal_v1'}%,'GenNormal_v2',}
          extraArgs{2}(1:2) = [cStat.dMean(cRing);cStat.dStd(cRing)];
        case 'Lognormal'
          extraArgs{2}(:) = [mean(deslocated_rings);cStat.dStd(cRing)];
        case {'SkewedNormal'}
          %extraArgs{2}(1:2) = [cStat.dMean(cRing);1];
          extraArgs{2}(1:2) = [mean(deslocated_rings);cStat.dStd(cRing)];
        case 'SkewedLaplace'
          %k = extraArgs{2}(3);
          extraArgs{2}(1:2) = [...
            mean(deslocated_rings);cStat.dStd(cRing)];
        case 'InvGauss'
          extraArgs{2}(:) = [mean(deslocated_rings);1];
        case 'Uniform'
          extraArgs{2}(:) = [cLB cUB];
        end

        % Test multiple distributions:
        [fitParams{cDist}(cRing,:),fitParamsCI{cDist,cRing}] = ...
          mle(deslocated_rings,distArgs{:},extraArgs{:},...
          'alpha',1-opts.mle_confidence);
         
        mle_estimates = num2cell(fitParams{cDist}(cRing,:));

        tempVar = [rings;...
          cdfFun(distType,deslocated_rings,mle_estimates{:})]';
        tempVar = sort(tempVar);
        % SORT IDX ON RINGS
        idx = true;
        [~,ia] = unique(tempVar(:,2));
        tempVar = tempVar(ia,:);

        % Estimate number of counts for each bin:
        cdf_estimates = cdfFun(distType,...
          deslocated_edges,mle_estimates{:});
        % Probability estimate for each bin:
        p_estimates = diff(cdf_estimates);
        % Add outliers probability at lower and upper bins:
        p_underflow_estimate = cdfFun(distType,...
          deslocated_edges(1),mle_estimates{:});
        p_estimates(1) = p_estimates(1) + p_underflow_estimate;
        p_overflow_estimate = 1-cdfFun(distType,...
          deslocated_edges(end),mle_estimates{:});
        p_estimates(end) = p_estimates(end) + p_overflow_estimate;
        p_estimates(p_estimates<=0) = 1e-322;

        % Keep its record:
        counts_estimates{cDist}(cRing,:) = p_estimates*nSamples;

        % Kolmogorov-Smirnov Test:
        [ksgof_h(cRing,cDist),ksgof_p(cRing,cDist),...
          ksgof_stat(cRing,cDist),ksgof_cv(cRing,cDist)] = ...
          kstest(tempVar(:,1),'CDF',tempVar,'alpha',...
          opts.test_significance);
        if ~ksgof_h(cRing,cDist)
          Output.INFO([...
            'Accepted H0 (p=%g) for %s distribution with significance'...
            ' level %f on ksgof.'],...
            ksgof_p(cRing,cDist),...
            dist2test{cDist},...
            opts.test_significance);
        else
          Output.DEBUG([...
            'Rejected H0 (p=%g) for %s distribution with significance'...
            ' level %f on ksgof.'],...
            ksgof_p(cRing,cDist),...
            dist2test{cDist},...
            opts.test_significance);
        end

        % Chi2 Test:
        % Two chi2 tests, one with the histograms I set:
        [chi2gof_hist_h(cRing,cDist),chi2gof_hist_p(cRing,cDist),...
          chi2gof_hist_stat] = chi2gof(cStat.enBinsCenters(cRing,:),...
          'Ctrs',cStat.enBinsCenters(cRing,:),...
          'expected',counts_estimates{cDist}(cRing,:),...
          'frequency',cStat.counts(cRing,:),'NParams',...
          numel(mle_estimates),'Alpha',opts.test_significance);
        if isnan(chi2gof_hist_p(cRing,cDist))
          chi2gof_hist_p(cRing,cDist) = 0;
          chi2gof_hist_h(cRing,cDist) = 1;
        end

        % Another with the default histogram matlab will mount:
        [chi2gof_h(cRing,cDist),chi2gof_p(cRing,cDist),...
          chi2gof_stat(cRing,cDist)] = chi2gof(deslocated_rings,...
          'cdf',@(in) cdfFun(distType,in,mle_estimates{:}),...
          ...%'frequency',cStat.counts(cRing,:)*(nBins*(cUB-cLB)),
          'NParams',numel(mle_estimates),'NBins',opts.chi2NBins,...
          'Alpha',opts.test_significance);
        if isnan(chi2gof_p(cRing,cDist))
          chi2gof_p(cRing,cDist) = 0;
          chi2gof_h(cRing,cDist) = 1;
        end

        if ~chi2gof_hist_h(cRing,cDist)
          Output.INFO([...
            'Accepted H0 (p=%g) for %s distribution with significance'...
            ' level %f on chi2gof test 1.'],...
            chi2gof_hist_p(cRing,cDist),...
            dist2test{cDist},...
            opts.test_significance);
        else
          Output.DEBUG([...
            'Rejected H0 (p=%g) for %s distribution with significance'...
            ' level %f on chi2gof test 1.'],...
            chi2gof_hist_p(cRing,cDist),...
            dist2test{cDist},...
            opts.test_significance);
        end
        if ~chi2gof_h(cRing,cDist)
          Output.INFO([...
            'Accepted H0 (p=%g) for %s distribution with significance'...
            ' level %f on chi2gof test 2.'],...
            chi2gof_p(cRing,cDist),...
            dist2test{cDist},...
            opts.test_significance);
        else
          Output.DEBUG([...
            'Rejected H0 (p=%g) for %s distribution with significance'...
            ' level %f on chi2gof test 2.'],...
            chi2gof_p(cRing,cDist),...
            dist2test{cDist},...
            opts.test_significance);
        end
      end
    end
  end

  % Variables to keep track from the tests:
  ksgofRes.ksgof_h = ksgof_h;
  ksgofRes.ksgof_p = ksgof_p;
  ksgofRes.ksgof_stat = ksgof_stat;
  ksgofRes.ksgof_cv = ksgof_cv;

  chi2gofRes.chi2gof_hist_h = chi2gof_hist_h;
  chi2gofRes.chi2gof_hist_p = chi2gof_hist_p;
  chi2gofRes.chi2gof_hist_stat = chi2gof_hist_stat;

  chi2gofRes.chi2gof_h = chi2gof_h;
  chi2gofRes.chi2gof_p = chi2gof_p;
  chi2gofRes.chi2gof_stat = chi2gof_stat;

end

function [dNonZeroesMode,figH,axesH,ringHistH,ringEstH,...
    fitTextH] =  getHistGrid(cStat,opts)

  %if cStat.nRings == 1
  % gridToUse = [1 1];
  %else
  % gridToUse = [1 2];
  % while prod(gridToUse) < cStat.nRings
  %   gridToUse = [gridToUse(2) (gridToUse(2)+1)];
  % end
  %end

  distTested = cStat.distTested;

  jobVec = {};

  ringHistH = {};
  ringEstH = {};
  fitTextH = {};
  axesH = {};
  figH = {};

  if opts.drawHistGrid
    if opts.drawEmpiricalData
      jobVec = [jobVec {'Empirical Data'}];

      axesH = [axesH cell(1)];
      figH = [figH cell(1)];
      ringHistH = [ringHistH cell(1)];
      ringEstH = [ringEstH cell(1)];
      fitTextH = [fitTextH cell(1)];
    end
    if opts.drawOneByOneFit
      jobVec = [jobVec distTested];

      axesH = [axesH cell(1,numel(distTested))];
      figH = [figH cell(1,numel(distTested))];
      ringHistH = [ringHistH cell(1,numel(distTested))];
      ringEstH = [ringEstH cell(1,numel(distTested))];
      fitTextH = [fitTextH cell(1,numel(distTested))];
    end
    if opts.drawBestFit
      jobVec = [jobVec {'Best Fit'}];

      axesH = [axesH cell(1)];
      figH = [figH cell(1)];
      ringHistH = [ringHistH cell(1)];
      ringEstH = [ringEstH cell(1)];
      fitTextH = [fitTextH cell(1)];
    end
  else
    jobVec = {'GetInfo'};
  end

  hLines = [8 repmat(8,1,8) 8 8 4 4 4];
  hColumns = numel(hLines);
  %if opts.debug
  %  hColumns = 2;
  %end

  % FIXME This is not working as expected
  %if isempty(jobVec)
  %  Output.INFO(['It will not get hist information '...
  %    'as it was not required by user.']);
  %  return;
  %end

  for jIdx = 1:numel(jobVec)

    Output.INFO('Extracting hist grid for %s',jobVec{jIdx});

    jobPlotFit = true;
    jobPlot = true;

    switch jobVec{jIdx}
    case 'Best Fit'
      jobChi2HistP = cStat.chi2gofRes.chi2gof_hist_p;
      jobChi2HistH = cStat.chi2gofRes.chi2gof_hist_h;
      jobChi2P = cStat.chi2gofRes.chi2gof_p;
      jobChi2H = cStat.chi2gofRes.chi2gof_h;
      jobKSP = cStat.ksgofRes.ksgof_p;
      jobKSH = cStat.ksgofRes.ksgof_h;

      jobEstimates = cStat.counts_estimates;

      jobFitParamsCI = cStat.fitParamsCI;
      jobFitParams = cStat.fitParams;

      jobDist2TestLabels = distTested;

      jobFigName = 'Best_Fit';
    case 'Empirical Data'
      jobPlotFit = false;
      jobFigName = 'Empirical_Data';
      %jobEstimates = cStat.counts_estimates;
    case 'GetInfo'
      jobPlot = false;
      jobPlotFit = false;
    otherwise
      distIdx = find(strcmp(jobVec{jIdx},distTested),1);

      jobChi2HistP = cStat.chi2gofRes.chi2gof_hist_p(:,distIdx);
      jobChi2HistH = cStat.chi2gofRes.chi2gof_hist_h(:,distIdx);
      jobChi2P = cStat.chi2gofRes.chi2gof_p(:,distIdx);
      jobChi2H = cStat.chi2gofRes.chi2gof_h(:,distIdx);
      jobKSP = cStat.ksgofRes.ksgof_p(:,distIdx);
      jobKSH = cStat.ksgofRes.ksgof_h(:,distIdx);

      jobEstimates = cStat.counts_estimates(distIdx);

      jobFitParamsCI = cStat.fitParamsCI(distIdx,:);
      jobFitParams = cStat.fitParams(distIdx);

      jobDist2TestLabels = distTested(distIdx);

      jobFigName = jobDist2TestLabels{1};
    end

    if jobPlot == false
      jobPlotFit = false;
    end


    if jobPlot
      jobFigH = whiteFigure;
      jobAxesH = zeros(max(hLines),hColumns);
      cRing = 1;
      jobRingHistH = zeros(1,cStat.nRings);
      jobRingEstH = zeros(1,cStat.nRings);
      jobFitRingH = zeros(1,cStat.nRings);
      for cColumn=1:hColumns
        for cLine=1:hLines(cColumn)
          jobAxesH(cLine,cColumn) = subplot(max(hLines),...
            hColumns,cRing,'Parent',jobFigH);
          set(jobAxesH(cLine,cColumn),'NextPlot','add',... 
            'FontSize',8,'box','off',...
            'Layer','top');
          if cStat.underflows(cRing)
            underflowColorLabel = '\color{red}';
          else
            underflowColorLabel = '\color[rgb]{0 0.3922 0}';
          end
          if cStat.overflows(cRing)
            overflowColorLabel = '\color{red}';
          else
            overflowColorLabel = '\color[rgb]{0 0.3922 0}';
          end

          ylabel(jobAxesH(cLine,cColumn),sprintf(...
            '{\\color{black}#%d} {%s U:%.1f%%}|{%s O:%.1f%%}',...
            cRing,underflowColorLabel,cStat.underflows(cRing)*100,...
            overflowColorLabel,cStat.overflows(cRing)*100),...
            'FontSize',8);
          cRing = cRing + 1;
          if cRing>cStat.nRings
            continue;
          end
        end
      end
      GraphUtils.setCustomPlotArea(jobAxesH);
    end

    cRing = 1;
    for cColumn=1:hColumns
      for cLine=1:hLines(cColumn)
        [maxVEmp,maxIdx]=max(cStat.counts(cRing,:));
        dNonZeroesMode(cRing) = ...
          (cStat.enBinsCenters(cRing,maxIdx)+cStat.enBinsCenters(cRing,maxIdx+1))/2;
        if jobPlot
          % Select current axes:
          axes(jobAxesH(cLine,cColumn));
          % Draw hist:
          jobRingHistH(cRing) = ...
            bar(cStat.enBinsCenters(cRing,:),cStat.counts(cRing,:),...
            'FaceColor',opts.layerColors(whichLayer(cRing),:),'EdgeColor',...
            opts.layerColors(whichLayer(cRing),:));
          %text('Parent',jobAxesH(cLine,cColumn),'Position',...
          %  [0 .99  .01 .01],...
          %  'String',sprintf('%.2f%%',cStat.lowerBounds(cRing)*100),...
          %  'FontSize',8,'LineStyle','none',...
          %  'HorizontalAlignment','center',...                        
          %  'VerticalAlignment','baseline','Tag','LowerBound');
          % Make axes tight:
          cLB = cStat.lowerBounds(cRing);
          cUB = cStat.upperBounds(cRing);
          if ~jobPlotFit
            line([0 0],[0 max(cStat.counts(cRing,:))/2],'Color',[0 0 0],...
              'LineStyle','--','Parent',jobAxesH(cLine,cColumn));
            line(ones(1,2)*dNonZeroesMode(cRing),...
              [0 max(cStat.counts(cRing,:))/2],'Color',[0 0 0],...
              'LineStyle','-','Parent',jobAxesH(cLine,cColumn));
            line(ones(1,2)*cStat.dNonZeroesMean(cRing),...
              [0 max(cStat.counts(cRing,:))/2],'Color',[0 0 0],...
              'LineStyle',':','Parent',jobAxesH(cLine,cColumn));
          end
          %if cLine == hLines(cColumn) || cRing+hLines(cColumn)>cStat.nRings
          %  xlabel('Energy','FontSize',8);
          %else                                                      
          range = cUB-cLB;
          set(jobAxesH(cLine,cColumn),'XTick',...
            [cLB+range*.1 cLB+range*.5 cLB+range*.9]);
          set(jobAxesH(cLine,cColumn),'XTickLabel',...
            {num2str(cLB) sprintf('%.1f%%',cStat.zeroCounts(cRing)*100) ...
            num2str(cUB)});
          set(jobAxesH(cLine,cColumn),'YTickLabel',...
            []);

          bestDistIdx = 1;

          % Add fit if required:
          if opts.doFit && opts.doFitRings && jobPlotFit
            % Find best pdf estimate for this ring:
            [bestDist_chi2gof_hist_p,bestDist_chi2gof_hist_idx] = max(...
              jobChi2HistP(cRing,:));
            [bestDist_chi2gof_p,bestDist_chi2gof_matlab_idx] = max(...
              jobChi2P(cRing,:));
            [bestDist_ksgof_p,bestDist_ksgof_idx] = max(jobKSP(cRing,:));
            test_bestDist_idx = ...
              [bestDist_chi2gof_hist_idx...
              bestDist_chi2gof_matlab_idx...
              bestDist_ksgof_idx];
            test_bestDist_h = ...
              [jobChi2HistH(cRing,bestDist_chi2gof_hist_idx)...
              jobChi2H(cRing,bestDist_chi2gof_matlab_idx)...
              jobKSH(cRing,bestDist_ksgof_idx)];
            test_bestDist_p = ...
              [bestDist_chi2gof_hist_p ...
              bestDist_chi2gof_p ...
              bestDist_ksgof_p];

            % Check most voted distribution:
            [bestDistIdx,freq]=mode(test_bestDist_idx);

            switch freq
            case 3
              [bestTestProb,bestTestIdx]=max(test_bestDist_p);
            case 2
              demsk = find(test_bestDist_idx==bestDistIdx);
              [bestTestProb,bestTestIdx]=max(test_bestDist_p(...
                test_bestDist_idx==bestDistIdx));
              bestTestIdx = demsk(bestTestIdx);
            case 1
              [bestTestProb,bestTestIdx]=max(test_bestDist_p);
            end

            % If test did not pass most voted, check if some other
            % test passed: 
            changedDueToH0 = false;
            if test_bestDist_h(bestTestIdx) && any(~test_bestDist_h)
              demsk = find(~test_bestDist_h);
              [bestTestProb,bestTestIdx]=max(test_bestDist_p(...
                ~test_bestDist_h));
              bestTestIdx = demsk(bestTestIdx);
              changedDueToH0 = true;
              acceptedH0Tests = bestTestIdx;
            else
              % The H0 passed tests:
              acceptedH0Tests = find(...
                test_bestDist_idx==bestDistIdx & ...
                ~test_bestDist_h);
            end


            % Their p:
            acceptedH0p = test_bestDist_p(acceptedH0Tests);

            % And its name:
            distLabel = jobDist2TestLabels{bestDistIdx};

            if ~test_bestDist_h(bestTestIdx)
              if changedDueToH0
                color = [160 32 240]/255; % purple
              else 
                color = [0 0 1]; % Blue
              end
              jobRingEstH(cRing) = ...
                plot(jobAxesH(cLine,cColumn),...
                cStat.enBinsCenters(cRing,:),...
                jobEstimates{bestDistIdx}(cRing,:),...
                'Color',[0 0 0],'LineStyle','-',...
                'LineWidth',2);
              set(jobAxesH(cLine,cColumn),'XColor',color,...
                'YColor',color,'LineWidth',2);
            else
              set(jobAxesH(cLine,cColumn),'XColor',[.8 0 0],...
                'YColor',[.8 0 0]);
              jobRingEstH(cRing) = ...
                plot(jobAxesH(cLine,cColumn),...
                cStat.enBinsCenters(cRing,:),...
                jobEstimates{bestDistIdx}(cRing,:),...
                'Color',[0 0 0],'LineStyle','--');
            end
            if ~isempty(acceptedH0Tests)
              str = {['{\bf' distLabel '}']};
            else
              str = {distLabel};
            end
            if ~isempty(acceptedH0Tests)
              passedTests = '{\color[rgb]{0 0.3922 0}';
              for k = 1:numel(acceptedH0Tests)
                switch acceptedH0Tests(k)
                case 1
                  passedTests = [passedTests ' X^21,'];
                case 2
                  passedTests = [passedTests ' X^22,'];
                case 3
                  passedTests = [passedTests ' KS,'];
                end
              end
              passedTests(end) = '}';
              str{end+1} = passedTests;
            else
              bestTestStr = '{\color[rgb]{.8 0 .0}';
              switch bestTestIdx
              case 1
                bestTestStr = [bestTestStr ' X^21,'];
              case 2
                bestTestStr = [bestTestStr ' X^22,'];
              case 3
                bestTestStr = [bestTestStr ' KS,'];
              end
              bestTestStr(end) = '}';
              str{end+1} = bestTestStr;
            end
            paramStr = {};
            params = jobFitParamsCI{bestDistIdx,cRing};
            for k = 1:size(params,2)
              if any(isnan(params))
                paramStr{end+1} = sprintf(...
                  '(%.3g)',jobFitParams{bestDistIdx}(cRing,k));
              else
                paramStr{end+1} = sprintf('(%.3g,%.3g)',params(1,k),...
                  params(2,k));
              end
            end
            str(end+1:end+numel(paramStr)) = paramStr;
            str{end+1} = sprintf('{\\bf %.1f%%}',bestTestProb*100);

          elseif ~jobPlotFit
            % Ploting empirical data, add empirical mean, std, skewness,
            % kurt
            str = cell(1,4);
            str{1} = sprintf('%.3g',cStat.dNonZeroesMean(cRing));
            str{2} = sprintf('%.3g',cStat.dNonZeroesStd(cRing));
            str{3} = sprintf('%.3g',cStat.dNonZeroesSkewness(cRing));
            str{4} = sprintf('%.3g',cStat.dNonZeroesKurtosis(cRing));
          end

          maxVEst = 0;
          if exist('jobEstimates','var') && ...
              numel(jobEstimates{bestDistIdx}(cRing,2:end-1))>2
            maxVEst=max(jobEstimates{bestDistIdx}(cRing,2:end-1));
          end

          % Make axis tight:
          axis(jobAxesH(cLine,cColumn),([cLB cUB 0 max(maxVEmp,maxVEst)])) 

          if opts.doFit && opts.doFitRings && jobPlotFit
            xl = xlim(jobAxesH(cLine,cColumn));
            yl = ylim(jobAxesH(cLine,cColumn));
            % Add text:
            jobFitRingH(cRing) = text('Parent',jobAxesH(cLine,cColumn),...
              'String',str,'Units','data','Position',[xl(2) yl(2)],...
              'HorizontalAlignment','Right','VerticalAlignment','Top',...
              'FontSize',7);
          elseif ~jobPlotFit
            xl = xlim(jobAxesH(cLine,cColumn));
            yl = ylim(jobAxesH(cLine,cColumn));
            % Add text:
            jobFitRingH(cRing) = text('Parent',jobAxesH(cLine,cColumn),...
              'String',str,'Units','data','Position',[xl(2) yl(2)],...
              'HorizontalAlignment','Right','VerticalAlignment','Top',...
              'FontSize',7);
          end
        end

        cRing = cRing + 1;
        if cRing>cStat.nRings
          continue;
        end
      end
    end

    if jobPlot
      colorStr = ['{\color[rgb]{' sprintf('%f ',cStat.color) '}'];
      annotation(jobFigH,'TextBox',[(1. - 1./hColumns*3) 0.36 ...
        (1./hColumns*3) 0.04*3],...
        'String',...
        {['\bf ' colorStr ' Rings Energy (MeV)}'],...
        [colorStr ' \bf histograms for}'],...
        [colorStr cStat.dataLabel ' } ']},...
        'FontSize',24,'LineStyle','-',...
        'HorizontalAlignment','center',...
        'VerticalAlignment','middle','Tag','Title',...
        'FitBoxToText','on');
      emLayerLegendText = '';
      for k = 1:4
        switch k
        case 1
          layerLabel = 'PS';
        case 2
          layerLabel = 'EM1';
        case 3
          layerLabel = 'EM2';
        case 4
          layerLabel = 'EM2';
        end
        emLayerLegendText = [emLayerLegendText ...
          '\color[rgb]{' sprintf('%f ',opts.layerColors(...
          k,:)) '} ' layerLabel];
        if k~=4
          emLayerLegendText = [emLayerLegendText ' '];
        end
      end
      hadLayerLegendText = '';
      for k = (1:3)+4
        switch k
        case 5
          layerLabel = 'HAD1';
        case 6
          layerLabel = 'HAD2';
        case 7
          layerLabel = 'HAD3';
        end
        hadLayerLegendText = [hadLayerLegendText ...
          '\color[rgb]{' sprintf('%f ',opts.layerColors(...
          k,:)) '} ' layerLabel];
        if k~=7
          hadLayerLegendText = [hadLayerLegendText ' '];
        end
      end
      annotation(jobFigH,'TextBox',[(1. - 1./hColumns*3) 0.25 ...
        (1./hColumns*3) 0.04],...
        'String',...
        {'Layer Color Legend:',...
        emLayerLegendText,hadLayerLegendText},...
        'FontSize',18,'LineStyle','none',...
        'HorizontalAlignment','center',...                        
        'VerticalAlignment','baseline','Tag','Title');                                 
      annotation(jobFigH,'TextBox',[(1. - 1./hColumns*3) 0.10 ...
        (1./hColumns*3) 0.04],...
        'String',{'\bf Number of clusters for this dataset:',...
        num2str(cStat.nSamples)},...
        'FontSize',18,'LineStyle','none',...
        'HorizontalAlignment','center',...                        
        'VerticalAlignment','baseline','Tag','Info');
      axesH{jIdx} = jobAxesH;
      figH{jIdx} = jobFigH;
      ringHistH{jIdx} = jobRingHistH;
      ringEstH{jIdx} = jobRingEstH;
    end

    drawnow

    if opts.doFit && opts.doFitRings && jobPlotFit
      cRing = 1;
      for cColumn=1:hColumns
        for cLine=1:hLines(cColumn)
          xl = xlim(jobAxesH(cLine,cColumn));
          yl = ylim(jobAxesH(cLine,cColumn));
          ext=get(jobFitRingH(cRing),'Extent');
          set(jobFitRingH(cRing),'Position',[xl(2) yl(2)+ext(4)]);
          axis(jobAxesH(cLine,cColumn),([xl yl] + [0 0 0 1]*ext(4)));
          cRing = cRing + 1;
          if cRing>cStat.nRings
            continue;
          end
        end
      end
      fitTextH{jIdx} = jobFitRingH;
    end

    if jobPlot
      GraphUtils.NewZoomAndPan(jobAxesH);
    end

    % FIXME
    if opts.drawHistGrid && opts.savePlots
      figName = [cStat.dataLabel '_' jobFigName];
      figPath = [opts.outputFolder filesep figName];
      if isempty(strfind(' not found.','epswrite'))
        epswrite(double(jobFigH),[figPath '.eps'],...
          'Size','Screen')
      end
      saveas(jobFigH,[figPath '.png']);
    end

  end

end

function [figH,axesH,barsH]=plotMeanMedianMode(stats,opts)

  figH = whiteFigure;

  nLayerRings = opts.nLayerRings;
  layerEdges = [1 (cumsum(nLayerRings(1:end-1))+1)];
  layerLabels = opts.layerLabels;

  barsH = zeros(numel(stats),3);

  nonZeroesMean = zeros(stats(end).nRings,numel(stats));
  nonZeroesMedian = zeros(stats(end).nRings,numel(stats));
  nonZeroesMode = zeros(stats(end).nRings,numel(stats));
  color = cell(numel(stats),1);

  removeIdx = [];
  for  cStatI = 1:numel(stats)
    if ~isempty(stats(cStatI).nRings)
      nonZeroesMean(:,cStatI) = stats(cStatI).dNonZeroesMean(:);
      nonZeroesMedian(:,cStatI) = stats(cStatI).dNonZeroesMedian(:);
      nonZeroesMode(:,cStatI) = stats(cStatI).dNonZeroesMode(:);
      color{cStatI} = stats(cStatI).color;
    else
      removeIdx = [removeIdx cStatI];
    end
  end

  nonZeroesMean(:,removeIdx) = [];
  nonZeroesMedian(:,removeIdx) = [];
  nonZeroesMode(:,removeIdx) = [];
  stats(removeIdx) = [];
  color(removeIdx) = [];
  barsH(removeIdx,:) = [];

  axesH = zeros(3,1);

  axesH(1) = subplot(3,1,1,'Parent',figH);
  barsH(:,1) = ringsPlot(axesH(1),'Ring #','Energy (MeV)',...
    'Non Null Rings Mean',nonZeroesMean,...
    color);
  legend(stats.dataLabel);

    
  axesH(2) = subplot(3,1,2,'Parent',figH);
  barsH(:,2) = ringsPlot(axesH(2),'Ring #','Energy (MeV)',...
    'Non Null Rings Median',nonZeroesMedian,...
    color);

  axesH(3) = subplot(3,1,3,'Parent',figH);
  barsH(:,3) = ringsPlot(axesH(3),'Ring #','Energy (MeV)',...
    'Non Null Rings Mode (from Histogram)',nonZeroesMode,...
    color);

  drawnow

  textH = zeros(3,numel(layerEdges));
  textH(1,:) = plotLayers(axesH(1),barsH(:,1),layerEdges,layerLabels);
  textH(2,:) = plotLayers(axesH(2),barsH(:,2),layerEdges,layerLabels);
  textH(3,:) = plotLayers(axesH(3),barsH(:,3),layerEdges,layerLabels);

  GraphUtils.setCustomPlotArea(axesH);
  GraphUtils.NewZoomAndPan(axesH); 

  if opts.savePlots
    figName = 'MeanMedianMode';
    figPath = [opts.outputFolder filesep figName];
    if isempty(strfind(' not found.','epswrite'))
      epswrite(double(figH),[figPath '.eps'],...
        'Size','Screen')
    end
    saveas(figH,[figPath '.png']);
    newMaxV(1) = max(max(nonZeroesMean(:,end-1:end))); 
    newMaxV(2) = max(max(nonZeroesMedian(:,end-1:end))); 
    newMaxV(3) = max(max(nonZeroesMode(:,end-1:end))); 
    oldLim = zeros(numel(axesH),2);
    oldPos = zeros(3,numel(layerEdges));
    for cIdx = 1:numel(axesH)
      oldLim(cIdx,:) = ylim(axesH(cIdx));
      ylim(axesH(cIdx),[oldLim(1) newMaxV(cIdx)]);
      for k = 1:numel(layerEdges)
        pos = get(textH(cIdx,k),'Position');
        oldPos(cIdx,k) = pos(1);
        set(textH(cIdx,k),'Position',[oldPos(cIdx,k) newMaxV(cIdx)]);
      end
    end

    figName = 'MeanMedianMode_BkgZoom';
    figPath = [opts.outputFolder filesep figName];
    if isempty(strfind(' not found.','epswrite'))
      epswrite(double(figH),[figPath '.eps'],...
        'Size','Screen')
    end
    saveas(figH,[figPath '.png']);

    for cIdx = 1:numel(axesH)
      ylim(axesH(cIdx),oldLim(cIdx,:));
      for k = 1:numel(layerEdges)
        set(textH(cIdx,k),'Position',[oldPos(cIdx,k) oldLim(cIdx,2)]);
      end
    end
  end

  %GraphUtils.plotuncertain(...
  %  axesH(1),1:numel(dMean),dMean,dStd,color);

  %uistack(dispersionH(:,cIdx),'bottom')   

  % TODO Custom datatip

end

function [figH,axesH,barsH,...
    figHNoOutlier,axesHNoOutlier,barsHNoOutlier...
    ]=plotRMSSkewnessKurt(stats,opts)

  figH = whiteFigure;

  nLayerRings = opts.nLayerRings;
  layerEdges = [1 (cumsum(nLayerRings(1:end-1))+1)];
  layerLabels = opts.layerLabels;

  barsH = zeros(numel(stats),3);
  barsHNoOutlier = zeros(numel(stats),3);

  nonZeroesStd = zeros(stats(end).nRings,numel(stats));
  nonZeroesSkewness = zeros(stats(end).nRings,numel(stats));
  nonZeroesKurtosis = zeros(stats(end).nRings,numel(stats));
  nonZeroesNoOutlierStd = zeros(stats(end).nRings,numel(stats));
  nonZeroesNoOutlierSkewness = zeros(stats(end).nRings,numel(stats));
  nonZeroesNoOutlierKurtosis = zeros(stats(end).nRings,numel(stats));
  color = cell(numel(stats),1);

  removeIdx = [];
  for  cStatI = 1:numel(stats)
    if ~isempty(stats(cStatI).nRings)
      nonZeroesStd(:,cStatI) = stats(cStatI).dNonZeroesStd(:);
      nonZeroesSkewness(:,cStatI) = stats(cStatI).dNonZeroesSkewness(:);
      nonZeroesKurtosis(:,cStatI) = stats(cStatI).dNonZeroesKurtosis(:);
      nonZeroesNoOutlierStd(:,cStatI) = ...
        stats(cStatI).dNoOutlierNonZeroesStd(:);
      nonZeroesNoOutlierSkewness(:,cStatI) = ...
        stats(cStatI).dNoOutlierNonZeroesSkewness(:);
      nonZeroesNoOutlierKurtosis(:,cStatI) = ...
        stats(cStatI).dNoOutlierNonZeroesKurtosis(:);
      color{cStatI} = stats(cStatI).color;
    else
      removeIdx = [removeIdx cStatI];
    end
  end

  nonZeroesStd(:,removeIdx) = [];
  nonZeroesSkewness(:,removeIdx) = [];
  nonZeroesKurtosis(:,removeIdx) = [];
  nonZeroesNoOutlierStd(:,removeIdx) = [];
  nonZeroesNoOutlierSkewness(:,removeIdx) = [];
  nonZeroesNoOutlierKurtosis(:,removeIdx) = [];
  stats(removeIdx) = [];
  color(removeIdx) = [];
  barsH(removeIdx,:) = [];
  barsHNoOutlier(removeIdx,:) = [];

  axesH = zeros(3,1);

  axesH(1) = subplot(3,1,1,'Parent',figH);
  barsH(:,1) = ringsPlot(axesH(1),'Ring #','',...
    'Non Null Rings RMS',nonZeroesStd,...
    color);
  legend(stats.dataLabel);
    
  axesH(2) = subplot(3,1,2,'Parent',figH);
  barsH(:,2) = ringsPlot(axesH(2),'Ring #','',...
    'Non Null Rings Skewness',nonZeroesSkewness,...
    color);

  axesH(3) = subplot(3,1,3,'Parent',figH);
  barsH(:,3) = ringsPlot(axesH(3),'Ring #','',...
    'Non Null Rings Kurtosis (Normalized)',nonZeroesKurtosis,...
    color);

  drawnow

  textH = zeros(3,numel(layerEdges));
  textH(1,:) = plotLayers(axesH(1),barsH(:,1),layerEdges,layerLabels);
  textH(2,:) = plotLayers(axesH(2),barsH(:,2),layerEdges,layerLabels);
  textH(3,:) = plotLayers(axesH(3),barsH(:,3),layerEdges,layerLabels);

  figHNoOutlier = whiteFigure;
  axesHNoOutlier = zeros(3,1);

  axesHNoOutlier(1) = subplot(3,1,1,'Parent',figHNoOutlier);
  barsHNoOutlier(:,1) = ringsPlot(axesHNoOutlier(1),...
    'Ring #','',...
    sprintf('Non Null Rings RMS for %.1f%% data',...
    opts.histPercentage*100),nonZeroesNoOutlierStd,color);
  legend(stats.dataLabel);

  axesHNoOutlier(2) = subplot(3,1,2,'Parent',figHNoOutlier);
  barsHNoOutlier(:,2) = ringsPlot(axesHNoOutlier(2),...
    'Ring #','',...
    sprintf('Non Null Rings Skewness for %.1f%% data',...
    opts.histPercentage*100),nonZeroesNoOutlierSkewness,color);

  axesHNoOutlier(3) = subplot(3,1,3,'Parent',figHNoOutlier);
  barsHNoOutlier(:,3) = ringsPlot(axesHNoOutlier(3),...
    'Ring #','',...
    sprintf('Non Null Rings Kurtosis (Normalized) for %.1f%% data',...
    opts.histPercentage*100),nonZeroesNoOutlierKurtosis,color);

  textHNoOutlier = zeros(3,numel(layerEdges));
  textHNoOutlier(1,:) = plotLayers(axesHNoOutlier(1),...
    barsHNoOutlier(:,1),layerEdges,layerLabels);
  textHNoOutlier(2,:) = plotLayers(axesHNoOutlier(2),...
    barsHNoOutlier(:,2),layerEdges,layerLabels);
  textHNoOutlier(3,:) = plotLayers(axesHNoOutlier(3),...
    barsHNoOutlier(:,3),layerEdges,layerLabels);

  GraphUtils.setCustomPlotArea(axesH);
  GraphUtils.NewZoomAndPan(axesH); 
  GraphUtils.setCustomPlotArea(axesHNoOutlier);
  GraphUtils.NewZoomAndPan(axesHNoOutlier); 

  if opts.savePlots
    figName = 'StdMeanKurt';
    figPath = [opts.outputFolder filesep figName];
    if isempty(strfind(' not found.','epswrite'))
      epswrite(double(figH),[figPath '.eps'],...
        'Size','Screen')
    end
    saveas(figH,[figPath '.png']);
    figName = 'StdMeanKurt_NoOutlier';
    figPath = [opts.outputFolder filesep figName];
    if isempty(strfind(' not found.','epswrite'))
      epswrite(double(figHNoOutlier),[figPath '.eps'],...
        'Size','Screen')
    end
    saveas(figHNoOutlier,[figPath '.png']);
  end

end

function barsH = ringsPlot(axesH,xlab,ylab,titleLabel,in,...
    color)

  set(axesH,'NextPlot','add',... 
    'FontSize',12,'box','off',...
    'Layer','top','YScale','Linear','YGrid','on',...
    'YMinorGrid','on');
  ylabel(ylab,'FontSize',14);
  xlabel(xlab,'FontSize',14);
  title(titleLabel);
  barsH = bar(in); barsH = barsH(:);
  for cStatI = 1:numel(color)
    set(barsH(cStatI),'FaceColor',color{cStatI},...
      'EdgeColor',color{cStatI},...
      'UserData','Ring #');
  end
  axis('tight');
end

function [linearCorrelations,nonLinearCorrelations,...
    figH,figNonLinearH] = getCorrelations(cData,cStats,opts);

  rings = cData.el_rings_E';

  linearCorrelations = corr(rings,rings);
  for k=1:size(rings,2)
    linearCorrelations(k,k) = 0;
  end
  if opts.doNonLinearCorrelations
    nonLinearCorrelations = corr(rings,tanh(rings));
  else
    nonLinearCorrelations = [];
  end

  titleLabel = ['Rings Correlation for dataset: \bf'...
    cStats.dataLabel];
  %FIXME
  %figH = plotMatrix(linearCorrelations,titleLabel,opts,[-1 1]);
  figH = plotMatrix(linearCorrelations,titleLabel,opts);

  % Draw non-linear correlations:
  if opts.doNonLinearCorrelations
    titleLabel = ['Non-linear ' titleLabel];
    figNonLinearH = plotMatrix(nonLinearCorrelations,...
      titleLabel,opts,[-1 1]);
  else
    figNonLinearH = 0;
  end

  if opts.savePlots
    lab = cStats.dataLabel;
    figName = ['linearCorrelation_' lab];
    figPath = [opts.outputFolder filesep figName];
    if isempty(strfind(' not found.','epswrite'))
      epswrite(double(figH),[figPath '.eps'],...
        'Size','Screen')
    end
    saveas(figH,[figPath '.png']);

    if opts.doNonLinearCorrelations
      figName = ['nonLinearCorrelation_' lab];
      figPath = [opts.outputFolder filesep figName];
      if isempty(strfind(' not found.','epswrite'))
        epswrite(double(figNonLinearH),[figPath '.eps'],...
          'Size','Screen')
      end
      saveas(figNonLinearH,[figPath '.png']);
    end
  end

end

%function [klMatrix,figH] = getKLDivergence(cStat,opts)
%
%  %KLDiv(X,P1,P2,'sym')
%  klMatrix = zeros(cStat.nRings);
%
%  for cIdx1 = 1:numel(data)
%    rings1 = data(cIdx1).el_rings_E';
%    for cIdx2 = 1:numel(data)
%      if cIdx1 ~= cIdx2 && ~opts.doCrossDataCorrelations
%        linearCorrelations{cIdx1,cIdx2} = 0;
%        if opts.doNonLinearCorrelations
%          nonLinearCorrelations{cIdx1,cIdx2} = 0;
%        end
%        continue;
%      end
%      rings2 = data(cIdx2).el_rings_E';
%      linearCorrelations{cIdx1,cIdx2} = ...
%        corr(rings1,rings2);
%      if opts.doNonLinearCorrelations
%        nonLinearCorrelations{cIdx1,cIdx2} = ...
%          corr(rings1,tanh(rings2));
%      end
%    end
%
%    % TODO Non zero rings correlations
%    %nonNullRings1 = data(cIdx1).el_rings_E;
%  end
%
%  maxCorr = cellfun(@(in) max(max(abs(in))),...
%    linearCorrelations);
%  maxCorr = max(max(triu(maxCorr,1)));
%
%  if opts.doNonLinearCorrelations
%    maxNonLinearCorr = cellfun(@(in) max(max(abs(in))),...
%      nonLinearCorrelations);
%    maxNonLinearCorr = max(max(triu(maxNonLinearCorr,1)));
%  end
%
%  for cIdx1 = 1:numel(data)
%    for cIdx2 = 1:numel(data)
%      if opts.drawCorrelationMatrix && ...
%          cIdx1>=cIdx2
%        if cIdx1==cIdx2
%          titleLabel = ['Rings Mutual Correlation for dataset: \bf'...
%            stats(cIdx1).dataLabel];
%        else
%          titleLabel = ['Rings Cross-correlation for datasets: {\bf'...
%            stats(cIdx1).dataLabel '} x {\bf' stats(cIdx2).dataLabel '}'];
%        end
%        maxZ = 1;
%        if cIdx1~=cIdx2
%          maxZ = maxCorr;
%        end
%        figH(cIdx1,cIdx2) = plotMatrix(...
%          linearCorrelations{cIdx1,cIdx2},...
%          titleLabel,stats(cIdx1).dataLabel,...
%          stats(cIdx2).dataLabel,opts,[-maxZ maxZ]);
%
%        % Draw non-linear correlations:
%        if opts.doNonLinearCorrelations
%          titleLabel = ['Non-linear ' titleLabel];
%          maxNonLinearZ = 1;
%          if cIdx1~=cIdx2
%            maxNonLinearZ = maxNonLinearCorr;
%          end
%          figNonLinearH(cIdx1,cIdx2) = plotMatrix(...
%            nonLinearCorrelations{cIdx1,cIdx2},...
%            titleLabel,stats(cIdx1).dataLabel,...
%            stats(cIdx2).dataLabel,opts,[-maxNonLinearZ ...
%            maxNonLinearZ]);
%        end
%      end
%    end
%  end
%
%
%end

function figH = plotMatrix(in,titleLabel,opts,clim)
  % Set jet and invert Z
  nLayerRings = opts.nLayerRings;
  layerEdges = [1 (cumsum(nLayerRings(1:end-1))+1)];
  layerLabels = opts.layerLabels;
  figH = whiteFigure(true);
  imagesc(in);
  colormap('jet');colorbar;
  title(titleLabel)
  set(gca,'Layer','Top','NextPlot','add','FontSize',...
    12,'box','on','DataAspectRatio',[1 1 1]);
  if nargin > 3
    set(gca,'CLim',clim);
  end
  axis equal;
  axis([1-0.5 size(in,1)+.5 1-.5 size(in,2)+.5]);
  %xlabel(sprintf('Ring # (%s)',label1))
  %ylabel(sprintf('Ring # (%s)',label2))
  xlabel('Ring #')
  ylabel('Ring #')
  set(gca,'YDir','normal');

  maxV = size(in,1);
  for cLayer = 1:numel(layerEdges)
    line(ones(1,2)*layerEdges(cLayer)-.5,...
      [0 maxV],'Color',[0 0 0],...
      'LineStyle','--','Parent',gca);
    line([0 maxV],...
      ones(1,2)*layerEdges(cLayer)-.5,...
      'Color',[0 0 0],'LineStyle','--','Parent',gca);
    text('Parent',gca,...
      'String',['\bf' layerLabels{cLayer}],'Units','data',...
      'Position',[layerEdges(cLayer)-.5 0-2],...
      'HorizontalAlignment','Right','VerticalAlignment','Top',...
      'FontSize',8,'Rotation',90);
    text('Parent',gca,...
      'String',['\bf' layerLabels{cLayer}],'Units','data',...
      'Position',[0-2 layerEdges(cLayer)+.5],...
      'HorizontalAlignment','Right','VerticalAlignment','Top',...
      'FontSize',8);
    %k=get(gca,'Title')
  end
end

function textH = plotLayers(hIn,barsH,localEdges,localLabels)
  limY = ylim(hIn);
  maxV = limY(2);
  textH = zeros(1,numel(localEdges));
  for cLayer = 1:numel(localEdges)
    line(ones(1,2)*localEdges(cLayer)-1/numel(barsH),...
      [0 maxV],'Color',[0 0 0],...
      'LineStyle','--','Parent',hIn);
    textH(cLayer) = text('Parent',hIn,...
      'String',['\bf' localLabels{cLayer}],'Units','data',...
      'Position',[localEdges(cLayer)-1/numel(barsH) maxV],...
      'HorizontalAlignment','Right','VerticalAlignment','Top',...
      'FontSize',8,'Rotation',90);
  end
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

function layer = whichLayer(cRing,method)
%
% TODO Help
%

% - Creation Date: Tue, 26 Aug 2014
% - Last Modified: Thu, 02 Oct 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  if nargin < 2
    method = 0;
  end
  nLayerRings = [8 64 8 8 4 4 4];

  layer = 1;
  while cRing>sum(nLayerRings(1:layer))
    layer = layer + 1;
  end
  if method
    layerCode = {'PS' 'EM1' 'EM2' 'EM3' 'HAD1' 'HAD2' 'HAD3'};
    layer = layerCode{layer};
  end
end

function out = getStatsInfoFor(mat,layer,method,nLayerRings,layerCode)
%
% Get strip from vec correspondent to layer using layerCode 
%

% - Creation Date: Wed, 20 Aug 2014
% - Last Modified: Thu, 02 Oct 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  if nargin < 5
  layerCode = {'ps' 'em1' 'em2' 'em3' 'had1' 'had2' 'had3'};
    if nargin < 4
      nLayerRings = [8 64 8 8 4 4 4];
			if nargin < 3
				method = 0;
			end
    end
	end

	cLayerIdx = find(strcmp(layerCode,layer),1);
  
	idx=sum(nLayerRings(1:cLayerIdx-1))+1:sum(nLayerRings(1:cLayerIdx));
	if method
		out=[[idx]' mat(idx,:)];
	else
		out=mat(idx,:);
	end
	
end

function F_x = laplace_cdf(x,mu,b,varargin)
  F_x = zeros(size(x));
  xlmu = x<mu;
  F_x(xlmu) = 1/2*exp((x(xlmu)-mu)/b);
  F_x(~xlmu) = 1-1/2*exp(-(x(~xlmu)-mu)/b);
  F_x(F_x<=0) = 0;
end

function f_x = laplace_pdf(x,mu,b,varargin)
  f_x = 1/(2*b)*exp(-abs(x-mu)/b);
  f_x(f_x<=0)=1e-322;
end

function F_x = maxwell_cdf(x,a,varargin)
  F_x = erf(x/(sqrt(2)*a)) - ...
    sqrt(2/pi)* (x .* exp( -x.^2/(2*a^2)))/a;
  F_x(F_x<=0) = 0;
end

function f_x = maxwell_pdf(x,a,varargin)
  if(any(x)<0)
    error(['There is a negative entry and Maxwell distribution '...
      'support is (0,inf)']);
  end
  f_x = (sqrt(2)/pi)*...
    (x.^2.*exp(-x.^2/(2*a^2)))/a^3+eps;
  f_x(f_x<=0)=1e-322;
end

function F_x = cauchy_cdf(x,mu,b,varargin)
  F_x = 1/pi * atan((x-mu)/b) + 1/2;
  F_x(F_x<=0) = 0;
end

function f_x = cauchy_pdf(x,mu,b,varargin)
  f_x = 1./(pi*b * (1 + ((x-mu)/b).^2 ));
  f_x(f_x<=0)=1e-322;
end

function F_x = inverse_gauss_cdf(x,mu,b,varargin)
  divx = b./x;
  xdivmu = x/mu;
  v1 = sqrt(divx).*(xdivmu-1);
  v2 = -sqrt(divx).*(xdivmu+1);
  Phi = @(in) 1/2*(1+erf(in/sqrt(2)));
  F_x = Phi(v1)+exp(2*b/mu)*Phi(v2);
  F_x(F_x<=0) = 0;
end

function f_x = inverse_gauss_pdf(x,mu,b,varargin)
  if(any(x)<0)
    error(['There is a negative entry and Maxwell distribution '...
      'support is (0,inf)']);
  end
  f_x = (b./(2*pi*x.^3)).^(1/2) .* ...
    exp((-b*(x-mu))./(2*mu^2*x));
  f_x(f_x<=0)=1e-322;
end

%function F_x = gumbel_cdf(x,mu,b,varargin)
%  z = (x-mu)/b;
%  F_x = exp(-exp(z-mu)/b);
%  F_x(F_x<=0) = 0;
%end
%
%function f_x = gumbel_pdf(x,mu,b,varargin)
%  z = (x-mu)/b;
%  f_x = 1/b*exp(-(z+exp(-z)));
%  f_x(f_x<=0)=1e-322;
%end

function F_x = gennormal_v1_cdf(x,mu,a,b,varargin)
  F_x = x;
  nx = numel(x);
  for k=1:numel(x)
    F_x(k) = integral(@(in) gennormal_v1_pdf(in,mu,a,b),-Inf,x(k));
    %msk = false(1,nx);
    %msk(1:k-1) = x(1:k-1)<x(k);
    %msk = F_x(msk)>F_x(k);
    %if any(msk)
    %  F_x(k) = max(F_x(msk))+eps;
    %end
  end
  F_x(F_x<=0) = 0;
end

function f_x = gennormal_v1_pdf(x,mu,a,b,varargin)
  f_x = b/(2*a*gamma(1/b))*exp(-(abs(x-mu)/a).^b);
  f_x(f_x<=0)=1e-322;
end


%function F_x = gennormal_v2_cdf(x,epsu,a,k,varargin)
%  %if k == 0
%  %  y = (x-epsu)/a;
%  %else
%  %  y = -1/k*log(1-k*(x-epsu)/a+eps);
%  %end
%  %F_x = cdf('norm',y,0,1);
%  %F_x(F_x<=0) = 0;
%  F_x = x;
%  nx = numel(x);
%  for k=1:numel(x)
%    F_x(k) = integral(@(in) gennormal_v2_pdf(in,epsu,a,k),-Inf,x(k));
%  end
%  F_x(F_x<=0) = 0;
%end
%
%function f_x = gennormal_v2_pdf(x,epsu,a,k,varargin)
%  if k == 0
%    y = (x-epsu)/a;
%  else
%    y = -1/k*log(1-k*(x-epsu)/a+eps);
%  end
%  f_x = pdf('norm',y,0,1)./(a-k*(x-epsu));
%  f_x(f_x<=0)=1e-322;
%end

function F_x = betaprime_cdf(x,a,b,varargin)
  F_x = betainc(x./(1+x),a,b);
  F_x(F_x<=0) = 0;
end

function f_x = betaprime_pdf(x,a,b,varargin)
  f_x = (x.^(a-1).*(1+x).^(-a-b))/beta(a,b);
  f_x(f_x<=0)=1e-322;
  f_x(~isfinite(f_x)) = 1e-322;
end

function f_x = gauss_skewed_pdf(x,epsu,omega,a,varargin)
  Phi = @(in) 1/2*(1+erf(in/sqrt(2)));
  phi = @(in) 1/sqrt(2*pi)*exp((-in.^2)/2);
  f_x = 2/omega*phi((x-epsu)/omega).*Phi(a*(x-epsu)/omega);
  f_x(f_x<=0)=1e-322;
end

function F_x = gauss_skewed_cdf(x,epsu,omega,a,varargin)
  F_x = x;
  nx = numel(x);
  for k=1:numel(x)
    F_x(k) = integral(@(in) gauss_skewed_pdf(in,epsu,omega,a),-Inf,x(k));
  end
  F_x(F_x<=0) = 0;
end

function f_x = laplace_skewed_pdf(x,theta,sigma,k,varargin)
  f_x = zeros(size(x));
  xltheta = x<theta;
  % Greater than and equal:
  f_x(~xltheta) = 1/sigma * k/(1+k^2) * ...
    exp(-k/sigma * (x(~xltheta)-theta));
  % Lower than:
  f_x(xltheta) = 1/sigma * k/(1+k^2) *  ...
    exp(-1/(sigma*k) * (-x(xltheta)+theta));
  f_x(f_x<=0) = 1e-322;
end

function F_x = laplace_skewed_cdf(x,theta,sigma,k,varargin)
  F_x = x;
  nx = numel(x);
  for k=1:numel(x)
    F_x(k) = integral(@(in) laplace_skewed_pdf(in,theta,sigma,k),-Inf,x(k));
  end
  F_x(F_x<=0) = 0;
end

