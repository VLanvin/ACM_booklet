#define SIZE     524288*2
#define PRIME    1004535809
#define NTHROOT  848723745
#define NTHROOTI 97543274
#define SIZEI    1004534851

typedef std::valarray<long> IArray;

long negative_mod (long v, long p) {
  if(v < 0) 
    return (v%p)+p;
  else
    return v%p;
}

long modpowsq (long v, long n, long p) {
  if (n == 1) 
    return v;
  else
    return modpowsq ((v*v)%p,n/2,p);
}

void fft (IArray& data, long root) {
  const size_t S = data.size();

  if(S <= 1) return;
  
  IArray even = data[std::slice(0, S/2, 2)];
  IArray odd  = data[std::slice(1, S/2, 2)]; 

  fft (even, root);
  fft (odd , root);

  long r = 1;
  long root_p = modpowsq (root, SIZE/S, PRIME);
  for (size_t k = 0; k < S/2; ++k)
  {
    long t    = (r * odd[k]) % PRIME;
    r = (r * root_p) % PRIME;
    data[k    ] = (even[k] + t) % PRIME;
    data[k+S/2] = (even[k] - t) % PRIME;
  }
}

void convolve (IArray& data) {
  fft(data, NTHROOT);

  for (int i = 0; i < SIZE; i++) {
    data[i] = (data[i] * data[i]) % PRIME;
  }

  fft(data, NTHROOTI);

  for (int i = 0; i < SIZE; i++) {
    data[i] = negative_mod (data[i] * SIZEI, PRIME);
  }
}


