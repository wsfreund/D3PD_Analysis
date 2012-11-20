function [SP_max, s_eff, b_fal, lim] = rocPlain(net,sgn_cl_size,bkg_cl_size,...
    sgn,bkg,sgn_tst_clusters,bkg_tst_clusters,param)

    sgn = sgn(:,create_cluster(sgn_cl_size,sgn_tst_clusters));
    bkg = bkg(:,create_cluster(bkg_cl_size,bkg_tst_clusters));
    Ys = sim(net,sgn);
    Yb = sim(net,bkg);

    astep = 0.001;

    edges = -1:astep:1;

    Ar = 0;
    ind = 1;
    SP=zeros(size(Ys));
    for a=edges
        sgn_eff(ind) = length(find(Ys > a))/length(Ys);
        bkg_eff(ind) = length(find(Yb < a))/length(Yb);
        bkg_false(ind) = 1 - bkg_eff(ind);
        SP(ind) = sqrt(((sgn_eff(ind) + bkg_eff(ind))/2)*sqrt(sgn_eff(ind)*bkg_eff(ind)));
        ind = ind + 1;

    end

    % Sort bkg_false
    [bkg_false,indices] = sort(bkg_false);

    sgn_eff = sgn_eff(indices);
    SP = SP(indices);

    for a = 2:ind-1
        Ar = Ar + ((sgn_eff(a)+sgn_eff(a-1))/2)*(bkg_false(a)-bkg_false(a-1));
    end

    [SP_max, ind_SP_max] = max(SP);

    if (nargout >= 3)
        s_eff = sgn_eff(ind_SP_max);
        b_fal = bkg_false(ind_SP_max);
    end

    if (nargout == 4)
        lim = -1 + (ind_SP_max-1)*astep;
    end

    str = sprintf('SP: %0.2f (%0.2f, %0.2f)\nArea: %0.5f',...
          SP_max, 100*bkg_false(ind_SP_max), 100*sgn_eff(ind_SP_max), Ar);
    str

    if (nargin == 4)
      plot('v6',bkg_false,sgn_eff,param);
      hold on;

      xlabel('Background false positive');
      ylabel('Efficiency for Signal detection');
    end

end

