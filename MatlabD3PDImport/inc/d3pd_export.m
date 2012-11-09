function d3pd_export_bestNet(analysis,fileName)

hNNname = genvarname(sprintf('%d_hiddenNeurons',analysis.bestNeurons));
nNet = genvarname(sprintf('%d_net',analysis.(hNNname).bestNet));
nNetTrnInfo = genvarname(sprintf('%d_net_trnInfo',analysis.(hNNname).bestNet));

pyFile=fopen(analysis,'w');

fprintf(pyFile,'self.sgn_cl_size=%d\n',analysis.sgn_cl_size);
fprintf(pyFile,'self.bkg_cl_size=%d\n',analysis.bkg_cl_size);
fprintf(pyFile,'self.sgn_tst_clusters=[')
for k=1:length(analysis.(hNNname).(nNetTrnInfo).sgn_tst_clusters)
  fprintf(pyFile,'%d ',analysis.(hNNname).(nNetTrnInfo).sgn_tst_clusters(k));
end
fprintf(pyFile,']\n')
fprintf(pyFile,'self.bkg_tst_clusters=[')
for k=1:length(analysis.(hNNname).(nNetTrnInfo).bkg_tst_clusters)
  fprintf(pyFile,'%d ',analysis.(hNNname).(nNetTrnInfo).bkg_tst_clusters(k));
end
fprintf(pyFile,']\n')
fprintf(pyFile, 'self.ringerNNTrnWrt=%d',1); % TODO Change it to read an variable of analysis
fprintf(pyFile, 'self.sgnTrnPdgIdType=%d',11); % TODO Change it to read an variable of analysis
fprintf(pyFile, 'self.sgnTrnMotherPdgIdType=%d',22); % TODO Change it to read an variable of analysis
