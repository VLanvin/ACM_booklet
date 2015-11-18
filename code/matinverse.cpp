// INPUT   a matrix M of size N
// OUTPUT  the inverse I of M
void inverse() {
  for(int i = 0; i < N; i++) {
    int B[N]; // init to 0
    B[i] = 1;
    int X[N];
    linear_solve(M, X, B);
    for(int k = 0; k < N; k++) {
      I[k][i] = X[k];
    }
  }
}
