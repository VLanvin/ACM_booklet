// INPUT   adjacency lists E of size N (pair(weight, dest)), a source s
// OUTPUT  array of distances D between s and the rest
vector<vector<PII> > E(N);

for(int i = 0; i < N; i++) { // INIT
  if(i == s) D[i] = 0;
  else D[i] = INFTY;
  Pred[i] = (-1);
}

for(int k = 0; k < N - 1; k++) { //repeat until D is full
  for(int i = 0; i < N; i++) {
    for(vector<PII>::iterator it=E[i].begin(); it != E[i].end(); it++) {
      if(D[i] + it->first < D[it->second]) {
        D[it->second] = D[i] + it->first;
        Pred[it->second] = i;
      }
}}}

// If there is an edge (u,v) of weight w s.t. D[u] + w < D[v] then
// there is a negative-weight cycle
