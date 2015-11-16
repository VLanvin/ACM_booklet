// INPUT   nb of vertices N, start s, goal t
//         adjacency lists : pair(distance, vertex)
// OUTPUT  path[] : result is t, path[t], path[path[t]], etc...
vector<vector<PII> > edges(N);
  
// order elements s.t. the first is the nearest 
priority_queue<PII, vector<PII>, greater<PII> > Q;
vector<int> dist(N, INFTY), path(N, -1);
Q.push (make_pair (0, s));
dist[s] = 0;
while (!Q.empty()){
  PII p = Q.top();
  if (p.second == t) break;
  Q.pop();
  int cur = p.second;
  for (vector<PII>::iterator it=edges[cur].begin(); it!=edges[cur].end(); it++){
    if (dist[cur] + it->first < dist[it->second]){
      dist[it->second] = dist[cur] + it->first;
      path[it->second] = cur;
      Q.push (make_pair (dist[it->second], it->second));
    }
  }
}
