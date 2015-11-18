// INPUT   adjacency lists E, T[N] an array of booleans (two sets of vertices)
// OUTPUT  a maximal (symetrical) matching array Pair, number of matches
int Pair[N];   //init to N
int Dist[N+1]; //init to INF
bool BFS() {
  queue<int> Q;
  for(int i = 0; i < N; i++) {
    if(T[i]) {
      if(Pair[i] == N) {
        Dist[i] = 0;
        Q.push(i);
      } 
      else
        Dist[i] = INF;
    }
  }
  Dist[N] = INF;
  while(!Q.empty()) {
    int u = Q.top (); Q.pop ();
    if(Dist[u] < Dist[N]) {
      EACH(it, E[u]) {
        if(Dist[Pair[*it]] == INF) {
          Dist[Pair[*it]] = Dist[u] + 1;
          Q.push(Pair[*it]);
        }
      }
    }
  }
  return (Dist[N] != INF);
}

bool DFS(int u) {
  if(u != N) {
    EACH(it, E[u]) {
      if(Dist[Pair[*it]] == Dist[u] + 1) {
        if(DFS(Pair[*it])) {
          Pair[u] = *it;
          Pair[*it] = u;
          return true;
        }
      }
    }
    Dist[u] = INF;
    return false;
  }
  return true;
}

int hopcroftkarp() {
  int matching = 0;
  while(BFS()) {
    for(int i = 0; i < N; i++) {
      if(T[i] && Pair[i] == N && DFS(i))
        matching++;
    }
  }
  return matching;
}
