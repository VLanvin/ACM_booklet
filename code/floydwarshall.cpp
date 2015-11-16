// INPUT   graph G (matrix of size N)
// OUTPUT  matrix D of distances between pairs

for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
      D[i][j] = G[i][j]; // copy of G

for (int k = 0; k < N; k++)
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
