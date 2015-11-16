// INPUT   adjacency matrix G
// OUTPUT  nothing, does a DFS or a BFS

queue<int> Q; // or stack<int> Q; for DFS
int visited[N]; // init to 0
Q.push(from);
visited[from] = 1;
while(!Q.empty()) {
  int s = Q.front(); // Q.top() for DFS
  Q.pop();
  for(int i = 0; i < N; i++) {
    if(G[s][i] && !visited[i]) {
      Q.push(i);
      visited[i] = 1;
    }
  }
  // Do something with s
}
