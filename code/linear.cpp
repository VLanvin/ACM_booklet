// INPUT   a matrix A, a vector B, both of size N
// OUTPUT  a vector X s.t. AX = B
void linear_solve() {
  int L[N][N]; int U[N][N]; 
  LUdecomp(A,L,U);
  int D[N];
  for(int i = 0; i < N; i++) {
    D[i] = B[i];
    for(int j = 0; j < i; j++) {
      D[i] -= L[i][j] * D[j];
    }
    D[i] /= L[i][i];
  }
  for(int i = N-1; i >= 0; i--) {
    X[i] = D[i];
    for(int j = i+1; j < N; j++) {
      X[i] -= U[i][j] * X[j];
    }
  }
}
