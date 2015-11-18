// INPUT   a string S of length N, the searched word W of length M
// OUTPUT  the position at which W is found

int T[M]
// Builds the table T, must be called before KMP
void build_kmp_table() {
  T[0] = -1; T[1] = 0;
  int pos = 2; int cnd = 0;
  while(pos < M) {
    if(W[pos-1] == W[cnd]) {
      T[pos] = cnd+1;
      cnd++; pos++;
    }
    else if(cnd > 0)
      cnd = T[cnd];
    else {
      T[pos] = 0;
      pos++;
    }
  }
}

void KMP() {
  int m = 0; int i = 0;
  while(m+i < N) {
    if(W[i] = S[m+i]) {
      if(i == M-1)
        return m;
      i++;
    }
    else {
      if(T[i] > -1) {
        m = m+i-T[i];
        i = T[i];
      }
      else {
        i = 0;
        m++;
      }
    }
  }
  return N;
}
