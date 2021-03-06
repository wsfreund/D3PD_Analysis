function [SP,sgn_eff,bkg_false] = getEffAtThres(thres,...
  classifier,dataStruct,evalStr)
%
% TODO Help
%

% - Creation Date: Sat, 27 Sep 2014
% - Last Modified: Mon, 29 Sep 2014
% - Author(s): 
%   - W.S.Freund <wsfreund_at_gmail_dot_com> 

  if nargin<4
    evalStr = 'tst';
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

    nYs = numel(Ys);
    nYb = numel(Yb);

    sgn_eff = sum(Ys > thres )/nYs*100;
    bkg_eff = sum(Yb < thres )/nYb*100;

    bkg_false = 100 - bkg_eff;
    SP = sqrt(((sgn_eff + bkg_eff)/2).*sqrt(sgn_eff.*bkg_eff));
  else
    sgn_eff = ...
      sum(classifier.userdata.labelFun(sgn)==1)/size(sgn,2)*100;
    bkg_eff = ...
      sum(classifier.userdata.labelFun(bkg)==-1)/size(bkg,2)*100;
    bkg_false = 100 - bkg_eff;
    SP = sqrt(((sgn_eff+bkg_eff)/2)*sqrt(sgn_eff*bkg_eff));
  end

end

