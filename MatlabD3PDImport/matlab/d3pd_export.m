function d3pd_export_bestNet(analysis,fileName)

hNNname = genvarname(sprintf('%d_hiddenNeurons',analysis.bestNeurons));
nNet = genvarname(sprintf('%d_net',analysis.(hNNname).bestNet));
nNetTrnInfo = genvarname(sprintf('%d_net_trnInfo',analysis.(hNNname).bestNet));

net2py(analysis.(hNNname).(nNet),fileName)
pyFile=fopen(fileName,'a');

fprintf(pyFile,'self.sgnCluster_size=%d\n',analysis.sgn_cl_size);
fprintf(pyFile,'self.bkgCluster_size=%d\n',analysis.bkg_cl_size);
fprintf(pyFile,'self.sgn_tst_clusters=[');
for k=1:length(analysis.(hNNname).(nNetTrnInfo).sgn_tst_clusters)-1
  fprintf(pyFile,'%d,',analysis.(hNNname).(nNetTrnInfo).sgn_tst_clusters(k));
end
fprintf(pyFile,'%d]\n',analysis.(hNNname).(nNetTrnInfo).sgn_tst_clusters(end));
fprintf(pyFile,'self.bkg_tst_clusters=[');
for k=1:length(analysis.(hNNname).(nNetTrnInfo).bkg_tst_clusters)-1
  fprintf(pyFile,'%d,',analysis.(hNNname).(nNetTrnInfo).bkg_tst_clusters(k));
end
fprintf(pyFile,'%d]\n',analysis.(hNNname).(nNetTrnInfo).bkg_tst_clusters(end));
if(strcmp(analysis.opts.trainWrt,'truth'))
  fprintf(pyFile,'self.ringerNNTrnWrt=%d\n',1);
  fprintf(pyFile,'self.sgnTrnPdgIdType=%d\n',analysis.opts.sgnTrnPdgIdType); 
  fprintf(pyFile,'self.sgnTrnMotherPdgIdType=%d\n',analysis.opts.sgnTrnMotherPdgIdType); 
elseif
  fprintf(pyFile,'self.ringerNNTrnWrt=%d\n',0);
  fprintf(pyFile,'self.sgnTrnIsEM_mask=%d\n',analysis.opts.sgnTrnIsEM_mask); 
  fprintf(pyFile,'self.sgnTrnMotherPdgIdType=%d\n',analysis.opts.bkgTrnIsEM_mask); 
end
fprintf(pyFile,'self.normalization=%s\n',analysis.opts.norm); 
