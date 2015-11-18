// INPUT   a matrix M of size N
// OUTPUT  two matrices L and U, lower- and upper-triangular (resp.)
//         s.t. M = LU. Then det(M) = det(L)*det(U).
void LUdecomp() {
  int sum = 0;
  for(int i = 0; i < N; i++) {
    U[i][i] = 1;
  }

  for (int j = 0; j < N; j++) {
    for (int i = j; i < N; i++) {
      sum = 0;
    for (int k = 0; k < j; k++) {
      sum = sum + L[i][k] * U[k][j];  
    }
    L[i][j] = M[i][j] - sum;
  }

  for (int i = j; i < N; i++) {
    sum = 0;
    for(int k = 0; k < j; k++) {
      sum = sum + L[j][k] * U[k][i];
    }
    if (L[j][j] == 0) {
      printf("det(L) close to 0!\n Can't divide by 0...\n");
      exit(EXIT_FAILURE);
    }
    U[j][i] = (M[j][i] - sum) / L[j][j];
  }
}
