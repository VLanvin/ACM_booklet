// INPUT   adjacency lists E of size N (pair(weight,dest))
// OUTPUT  a vector A of edges forming a min. spanning tree
// Uses the union-find structure with parent[N] and rank[N]
vector<PII> A;

for(int i = 0; i < N; i++) make(parent, rank, i);

for(vector<PII>::iterator it=E[i].begin(); it != E[i].end(); it++) {
  if(find(parent, rank, it.first) != find(parent, rank, it.second)) {
    A.push_back(make_pair(it.first, it.second));
    merge(parent, rank, it.first, it.second);
  }
}
