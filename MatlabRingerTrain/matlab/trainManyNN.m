function [MyTrainAnalysis] = trainManyNN(pathSgn,pathBkg,inputopts)
% function [MyTrainAnalysis] = trainManyNN(sgn,bkg,opts)

	defopts = struct('neurons',[5:20],'n_clusters',10,'n_clusters_train',6,...
		'n_clusters_val',2,'n_train',10,'trainMethod','trainrp',...
		'trainWrt','truth','useFastNet',1,'truth_type',11,'truth_mothertype',23,...
		'trnSgnIsEM_mask',966493,'trnBkgIsEM_mask',93,'norm','norm1',...
    'debug',false);

	if(~exist('inputopts','var')) 
		inputopts = struct; 
	end

	opts = scanparam(defopts,inputopts);

  if ischar(pathSgn)
    load(pathSgn);
  else isstruct(pathSgn)
    elc = pathSgn;
  end

  if ischar(pathBkg)
    load(pathBkg);
  else
    jet = pathBkg;
  end

	n_threads = str2double(getenv('OMP_NUM_THREADS'));

	isOpen = matlabpool('size');
	if isOpen ~= n_threads
		set(findResource(),'ClusterSize',n_threads)
		matlabpool('open',n_threads)
	end

	if(strcmp(opts.trainWrt,'truth'))
    sgn = elc.el_rings_E(:,abs(elc.el_truth_type)==opts.truth_type & elc.el_truth_mothertype==opts.truth_mothertype);
    bkg = jet.el_rings_E;
	elseif(strcmp(opts.trainWrt,'standard'))
    sgn = elc.el_rings_E(:,~(bitand(elc.el_isEM,opts.trnSgnIsEM_mask)));
    bkg = jet.el_rings_E(:,bitand(jet.el_isEM,opts.trnBkgIsEM_mask));
	else
		disp('Please use truth or standard as input to param trainWrt');
	end

	clear elc jet

	if(strcmp(opts.norm,'norm1'))
    sgn = sgn.*repmat(1./(sum(sgn,1)+eps),[100 1]);
    bkg = bkg.*repmat(1./(sum(bkg,1)+eps),[100 1]);
	end

  if opts.debug
    sgn = sgn(:,1:100);
    bkg = bkg(:,1:100);
  end

	MyTrainAnalysis.n_clusters = opts.n_clusters;

	MyTrainAnalysis.opts = opts;

	sgn_cl_size = floor(size(sgn,2)/opts.n_clusters);
	bkg_cl_size = floor(size(bkg,2)/opts.n_clusters);

	MyTrainAnalysis.sgn_cl_size = sgn_cl_size;
	MyTrainAnalysis.bkg_cl_size = bkg_cl_size;

	disp(sprintf('Cluster size for signal is:%d',MyTrainAnalysis.sgn_cl_size))
	disp(sprintf('Cluster size for background is:%d',MyTrainAnalysis.bkg_cl_size))

	total=length(opts.neurons);

	SP = zeros(total,opts.n_train);
	lim = zeros(total,opts.n_train);
	edet = zeros(total,opts.n_train);
	jfa = zeros(total,opts.n_train);

  for counter = 1:total
    %counter
    hNNname = genvarname(sprintf('%d_hiddenNeurons',opts.neurons(counter)));

		sgn_trn_clusters = zeros(opts.n_train,opts.n_clusters_train);
		sgn_val_clusters = zeros(opts.n_train,opts.n_clusters_val);
		sgn_tst_clusters = zeros(opts.n_train,opts.n_clusters-(opts.n_clusters_train+opts.n_clusters_val));

		bkg_trn_clusters = zeros(opts.n_train,opts.n_clusters_train);
		bkg_val_clusters = zeros(opts.n_train,opts.n_clusters_val);
		bkg_tst_clusters = zeros(opts.n_train,opts.n_clusters-(opts.n_clusters_train+opts.n_clusters_val));

		net_cell = cell(opts.n_train,opts.n_clusters_train);
		trainParam_cell = cell(opts.n_train,opts.n_clusters_train);

    % Repeat training n_train times with neurons(counter) neurons at hidden layer
    %for cont2 = 1:opts.n_train
    parfor cont2 = 1:opts.n_train
      disp(sprintf('Training network with %d hidden neurons (iteration %d):',opts.neurons(counter),cont2));

      perm_sgn = randperm(opts.n_clusters);

      tmp_sgn_trn_clusters = perm_sgn(1:opts.n_clusters_train);
      tmp_sgn_val_clusters = perm_sgn(opts.n_clusters_train+1:opts.n_clusters_train+opts.n_clusters_val);
      tmp_sgn_tst_clusters = perm_sgn(opts.n_clusters_train+opts.n_clusters_val+1:end);

      perm_bkg = randperm(opts.n_clusters);

      tmp_bkg_trn_clusters = perm_bkg(1:opts.n_clusters_train);
      tmp_bkg_val_clusters = perm_bkg(opts.n_clusters_train+1:opts.n_clusters_train+opts.n_clusters_val);
      tmp_bkg_tst_clusters = perm_bkg(opts.n_clusters_train+opts.n_clusters_val+1:end);
 
      % Get standartization params from train dataset
      %[a,trn_ps] = mapstd(...
      %  [...
      %    sgn(:,create_cluster(MyTrainAnalysis.sgn_cl_size,MyTrainAnalysis.(hNNname).(infoNNname).sgn_trn_clusters)),...
      %    bkg(:,create_cluster(MyTrainAnalysis.bkg_cl_size,MyTrainAnalysis.(hNNname).(infoNNname).bkg_trn_clusters))...
      %  ]...
      %);
      %clear a;
      
      %% Apply it. 
      %sgn = mapstd('apply',sgn,trn_ps);
      %bkg = mapstd('apply',bkg,trn_ps);

      [net_tmp, trainParam_cell{counter,cont2}] = ... 
        trainMyNN(opts.neurons(counter),sgn_cl_size,bkg_cl_size,sgn,bkg,...
          tmp_sgn_trn_clusters,... 
          tmp_sgn_val_clusters,...
          tmp_sgn_tst_clusters,...
          tmp_bkg_trn_clusters,... 
          tmp_bkg_val_clusters,...
          tmp_bkg_tst_clusters,...
          opts.trainMethod,opts.useFastNet);
      [SP_tmp, edet_tmp, jfa_tmp, lim_tmp] = rocPlain(net_tmp,...
          sgn_cl_size,bkg_cl_size,sgn,bkg,...
          tmp_sgn_tst_clusters,...
          tmp_bkg_tst_clusters...
      );

			net_cell{counter,cont2} = net_tmp;
      SP(counter,cont2) = SP_tmp;
      lim(counter,cont2) = lim_tmp;
      edet(counter,cont2) = edet_tmp;
      jfa(counter,cont2) = jfa_tmp;

      sgn_trn_clusters(cont2,:) = tmp_sgn_trn_clusters;
      sgn_val_clusters(cont2,:) = tmp_sgn_val_clusters;
      sgn_tst_clusters(cont2,:) = tmp_sgn_tst_clusters;

      bkg_trn_clusters(cont2,:) = tmp_bkg_trn_clusters;
      bkg_val_clusters(cont2,:) = tmp_bkg_val_clusters;
      bkg_tst_clusters(cont2,:) = tmp_bkg_tst_clusters;

      %% Remove standartization 
      %sgn = mapstd('reverse',sgn,trn_ps);
      %bkg = mapstd('reverse',bkg,trn_ps);

    end

    for cont2 = 1:opts.n_train
      nNet = genvarname(sprintf('%d_net',cont2));
      nNet_untrained = genvarname(sprintf('%d_net_untrained',cont2));
      infoNNname = genvarname(sprintf('%d_net_trnInfo',cont2));

      MyTrainAnalysis.(hNNname).(infoNNname).sgn_trn_clusters = sgn_trn_clusters(cont2,:);
      MyTrainAnalysis.(hNNname).(infoNNname).sgn_val_clusters = sgn_val_clusters(cont2,:);
      MyTrainAnalysis.(hNNname).(infoNNname).sgn_tst_clusters = sgn_tst_clusters(cont2,:);

      MyTrainAnalysis.(hNNname).(infoNNname).bkg_trn_clusters = bkg_trn_clusters(cont2,:);
      MyTrainAnalysis.(hNNname).(infoNNname).bkg_val_clusters = bkg_val_clusters(cont2,:);
      MyTrainAnalysis.(hNNname).(infoNNname).bkg_tst_clusters = bkg_tst_clusters(cont2,:);
 
      MyTrainAnalysis.(hNNname).(nNet) = net_cell{counter,cont2};
			MyTrainAnalysis.(hNNname).(infoNNname).trainParam = trainParam_cell{counter,cont2}; 

		end

		MyTrainAnalysis.(hNNname).SP = SP(counter,:);
		MyTrainAnalysis.(hNNname).edet = edet(counter,:);
		MyTrainAnalysis.(hNNname).jfa = jfa(counter,:);
		MyTrainAnalysis.(hNNname).lim = lim(counter,:);

    [maxSP, idx] = max(MyTrainAnalysis.(hNNname).SP);
    MyTrainAnalysis.bestSPs(counter) = maxSP; 
    MyTrainAnalysis.edet(counter) = MyTrainAnalysis.(hNNname).edet(idx); 
    MyTrainAnalysis.jfa(counter) = MyTrainAnalysis.(hNNname).jfa(idx); 
    MyTrainAnalysis.lim(counter) = MyTrainAnalysis.(hNNname).lim(idx); 
    MyTrainAnalysis.(hNNname).bestNet = idx;

    save MyTrainAnalysis MyTrainAnalysis
  
  end

  [maxNNSP, nnidx] = max(MyTrainAnalysis.bestSPs);
  MyTrainAnalysis.bestNNSP = maxNNSP;
  MyTrainAnalysis.neurons = opts.neurons;
  MyTrainAnalysis.bestNeurons = (nnidx-1)+opts.neurons(1);

  errorbar(opts.neurons, mean(SP,2), std(SP'));
  title('NeuralNetwork')
  xlabel('Neurons at the hidden layer');
  ylabel('SP');
  saveas(gcf, 'histNeurons', 'fig')

	disp('all ok')

end

