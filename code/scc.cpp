// INPUT   adjacency lists E of size N
// OUTPUT  a vector SCC of vectors of vertices (SCC)
vector<vector<int> > SCC;
vector<int> S;
int indices[N]; //init to -1
int lowlinks[N]; //init to -1
int stacked[N]; //init to 0
int curr_index = 0;

void strong_connect(int i) {
  indices[i] = curr_index;
  lowlinks[i] = curr_index;
  curr_index++;
  S.push_back(i);
  stacked[i] = 1;

  for (vector<int>::iterator it=E[i].begin(); it!=E[i].end(); it++){
    if(indices[*it] == -1) {
      strong_connect(*it, scc);
      lowlinks[i] = min(lowlinks[i], lowlinks[*it]);
    }
    else if(stacked[it.second] == 1) 
      lowlinks[i] = min(lowlinks[i], indices[*it]);
  }

  if(lowlinks[i] == indices[i]) {
    vector<int> scc;
    int w = -1;
    while(w != i) {
      w = S.back(); S.pop_back();
      stacked[w] = 0;
      scc.push_back(w);
    }
    SCC.push_back(scc);
  }
}

for(int i = 0; i < N; i++) {
  if(indices[i] == -1) 
    strong_connect(i);
}
