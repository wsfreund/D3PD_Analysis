function cluster = create_cluster(clusters_size,array)
% create cluster from array indices

  cluster = [];
  for k=1:length(array)
    cluster = [cluster [((array(k)-1)*clusters_size+1):array(k)*clusters_size]];
  end

