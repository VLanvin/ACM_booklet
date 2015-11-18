// INPUT   a graph G (matrix) of size N
// OUTPUT  a vector P of edges forming the eulerian tour
struct Edge {
  int from, to;
  Edge(int from, int to):from(from),to(to) {}
};
int deg[N];
vector<Edge> P;
void euler(int u) {
  for(int v = 0; v < N; v++) 
  if(G[u][v]) {
    G[u][v]--; G[v][u]--; //only G[u][v]--; for directed graph.
    euler(v);
    P.push_back(Edge(u, v));
  }
}

bool solve_euler_path() {
  bool solved = true;
  for(int i = 0; i < N; i++)
    if(deg[i] % 2 == 1) { solved = false; break; } 
  if(solved) {
    P.clear();
    euler(start);
    if(P.size() != N || P[0].to != P[P.size()-1].from) solved = false;
  }
  return solved;
}
