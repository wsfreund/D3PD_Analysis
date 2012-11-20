function [cl_size,n_clusters] = cluster_size(data,clusters_size)
% Randomly separe data into clusters with size of clusters_size.

  %data = data(:,randperm(length(data)));
  n_clusters = [floor(size(data,2)/clusters_size)+1 floor(size(data,2)/clusters_size)];
  data_max_size = n_clusters.*clusters_size;
  cl_size = clusters_size+floor((size(data,2)-data_max_size+1)./n_clusters);
  [a,idx] = min(abs(cl_size-clusters_size));
  cl_size=cl_size(idx);
  n_clusters=n_clusters(idx);
  

