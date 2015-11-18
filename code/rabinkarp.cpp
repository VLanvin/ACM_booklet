// INPUT   a string S of length N, a pattern W of length M
// OUTPUT  the index of the first occurence of W in S
//         (see : hash algorithm)
int RK() {
  int hpattern = hash(W, 0, M);
  int hs = hash(S, 0, M); // hash S[0..M-1]
  for(int i = 0; i <= N - M; i++) {
    if(hs == hpattern) {
      if(memcmp(S+i, W, M) == 0) 
        return i;
    }
    hs = hash(S, 1, M+1, hs);
  }
  return N;
}

