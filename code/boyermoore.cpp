// INPUT   a string S of length N, a pattern W of length M
// OUTPUT  the index of the first occurence of W

int T[256]; //Size of alphabet
// Must be called before BM
void build_bm_table() {
  for(int i = 0; i < 256; i++) 
    T[i] = M;
  for(int i = 0; i < M-1; i++) 
    T[W[i]] = M-1-i;
}

int BM() {
  int skip = 0;
  while(skip <= N - M) {
    if(S[skip + M - 1] == W[M - 1]) {
      if(memcmp(S+skip, W, M-2) == 0)
        return skip;
    }
    skip += T[S[skip + M - 1]];
  }
  return N;
}
