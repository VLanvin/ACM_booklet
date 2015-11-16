//  Union find data structure, with balancing. Can also be done with structs
void make(int *parent, int *rank, int n) {
  for(int i = 0; i < n; i++) {
    parent[i] = i; rank[i] = 0;
  }
}

int find(int *parent, int *rank, int x) {
  if(parent[x] = x) return x;
  parent[x] = find(parent, rank, parent[x]);
  return parent[x];
}

void merge(int *parent, int *rank, int x, int y) { //union is a keyword
  int rootx = find(parent, rank, x); int rooty = find(parent, rank, y);
  if(rank[rootx] > rank[rooty]) parent[rooty] = rootx;
  else if(rank[rootx] < rank[rooty]) parent[rootx] = rooty;
  else if(rootx != rooty) {parent[rooty] = rootx; rank[rootx]++;}
}
