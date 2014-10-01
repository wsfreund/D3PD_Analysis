function [thres,SP_max,s_eff,b_fal,Ar] = getThresAndEff(classifier,...
  dataStruct,evalStr,astep)


  if nargin < 4
    astep = 0.001;
    if nargin<3
      evalStr = 'tst';
    end
  end

  switch evalStr
  case 'tst'
    sgn = [dataStruct.sgn(:,...
      create_cluster(dataStruct.sgn_cl_size,...
        dataStruct.sgn_tst_clusters)) ...
      dataStruct.testSgnData];
    bkg = [dataStruct.bkg(:,...
      create_cluster(dataStruct.bkg_cl_size,...
        dataStruct.bkg_tst_clusters)) ...
      dataStruct.testBkgData];
  case 'allData'
    sgn = [dataStruct.sgn dataStruct.testSgnData];
    bkg = [dataStruct.bkg dataStruct.testBkgData];
  case 'val'
    if isfield(dataStruct,'useTstAsValidation') && ...
        dataStruct.useTstAsValidation
      sgn = [dataStruct.sgn(:,...
        create_cluster(dataStruct.sgn_cl_size,...
          dataStruct.sgn_tst_clusters)) ...
        dataStruct.testSgnData];
      bkg = [dataStruct.bkg(:,...
        create_cluster(dataStruct.bkg_cl_size,...
          dataStruct.bkg_tst_clusters)) ...
        dataStruct.testBkgData];
      evalStr = 'tst';
    else
      sgn = dataStruct.sgn(:,...
        create_cluster(dataStruct.sgn_cl_size,...
          dataStruct.sgn_val_clusters));
      bkg = dataStruct.bkg(:,...
        create_cluster(dataStruct.bkg_cl_size,...
          dataStruct.bkg_val_clusters));
    end
  case 'trn'
    sgn = dataStruct.sgn(:,...
      create_cluster(dataStruct.sgn_cl_size,...
      dataStruct.sgn_trn_clusters));
    bkg = dataStruct.bkg(:,...
      create_cluster(dataStruct.bkg_cl_size,...
        dataStruct.bkg_trn_clusters));
  end

  if ~isfield(classifier.userdata,'labelFun')
    Ys = classifier.userdata.outputFun(sgn);
    Yb = classifier.userdata.outputFun(bkg);

    edges = min(min(Ys),min(Yb)):astep:max(max(Ys),max(Yb));

    SP = zeros(size(Ys));

    nYs = numel(Ys);
    nYb = numel(Yb);

    ind = 1;
    for a=edges
      sgn_eff(ind) = sum(Ys > a)/nYs*100;
      bkg_eff(ind) = sum(Yb < a)/nYb*100;
      ind = ind + 1;
    end

    bkg_false = 100 - bkg_eff;
    SP = sqrt(((sgn_eff + bkg_eff)/2).*sqrt(sgn_eff.*bkg_eff));

    [SP_max,ind_SP_max] = max(SP);
    spMsk = SP==SP_max;
    if sum(spMsk)>2
      first = find(spMsk,1,'first');
      last = find(spMsk,1,'last');
      ind_SP_max = round((last+first)/2);
    end

    thres = -1 + (ind_SP_max-1)*astep;

    if (nargout >= 3)
      s_eff = sgn_eff(ind_SP_max);
      if (nargout >= 4)
        b_fal = bkg_false(ind_SP_max);
        if (nargout >= 5)
          Ar  = sum((sgn_eff(2:ind-1)+sgn_eff(1:ind-2))/2 ...
            .*(bkg_eff(2:ind-1)-bkg_eff(1:ind-2)));
          Output.INFO(...
            ['thres_%s = %f | SP: %0.2f (FA:%0.2f, DET:%0.2f) | '...
            'Area: %f'],...
             evalStr,thres,SP_max,bkg_false(ind_SP_max),... 
             sgn_eff(ind_SP_max),Ar);
        end
      end
    end
  else
    s_eff = sum(classifier.userdata.labelFun(sgn)==1)/size(sgn,2)*100;
    b_eff = sum(classifier.userdata.labelFun(bkg)==-1)/...
      size(bkg,2)*100;
    b_fal = 100 - b_eff;
    SP_max = sqrt(((s_eff+b_eff)/2)*sqrt(s_eff*b_eff));
    Ar = NaN;
    thres = NaN;
    Output.INFO(...
      ['thres_%s = %f | SP: %0.2f (FA:%0.2f, DET:%0.2f) | '...
      'Area: %f'],...
       evalStr,thres,SP_max,b_fal,... 
       s_eff,Ar);
  end


end

