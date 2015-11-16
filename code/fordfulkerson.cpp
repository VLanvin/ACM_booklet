// INPUT   adjacency lists E of size N (pair(capa, dest))
//         a source s, a destination t
// OUTPUT  value of the maximal flow from s to t
int flow[N][N];

bool find_path(int source, int sink, vector<PII> path) {
  if(source == sink) return true;
  for(vector<PII>::iterator it=E[source].begin(); it != E[source].end(); ++it) {
    int residual = it.first - flow[source][it.second];
    //find can be optimized
    if(residual > 0 && find(path.begin(), path.end(), make_pair(source, it.second)) == path.end()) {
      path.push_back(make_pair(source, it.second));
      return find_path(it.second, sink, path);
    }
  }
  return false;
}

vector<PII> path;
find_path(s, t, path);
while(!path.empty()) {
  int flow = 1000000000;
  for(vector<PII>::iterator it=path.begin(); it != path.end(); ++it) {
    int residual = E[it.first]
  }
}
