// v should be in [0;p[ !!
ll fme(ll v, ll n, ll p) {
  if(n == 0) return 1;
  if(n == 1) return v;
  if(n % 2 == 0) return fme((v * v)%p, n/2, p);
  return(v * fme((v*v)%p, n/2, p))%p;
}

// 2nd version :
ll fme(ll v, ll n, ll p) {
  ll r = 1;
  while(n > 0) {
    if(n & 1 > 0) r = (r * v) % p;
    n >>= 1;
    v = (v * v) % p;
  }
  return r;
}
