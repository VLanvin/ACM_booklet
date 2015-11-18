// INPUT   a string S of length N
// OUTPUT  a hash for the string
//         here the hash is computed modulo LARGE_PRIME, but can also
//         be done with the usual multiplication with unsigned ints 
//         and the result would be modulo 2^32
int hash(string S) {
  int res = 0;
  for(int i = 0; i < N; i++) {
    res += (S[N-i-1] * modpow(PRIME, i, LARGE_PRIME)) % LARGE_PRIME;
  }
  return res;
}

// For the Rabin-Karp algorithm, one can use the following function
// to compute the hash of the substring S[i..i+m-1] given the hash
// of the substring S[i-1...i+m-2]
int hash(string S, int i, int m, int prev) {
  return (PRIME * (prev - (S[i-1] * pow(PRIME, m-1))) + S[i+m-1]);
}
