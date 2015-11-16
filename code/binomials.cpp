ll binomial(ll k, ll n) {
  if(k == 0 || k == n)
    return 1;
  if(k > n)
    return 0;
  if(binomials[k][n] != 0) 
    return binomials[k][n];
  ll r = (n * binomial(k-1, n-1))/k;
  binomials[k][n] = r;
  return r;
}
