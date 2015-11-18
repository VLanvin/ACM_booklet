// INPUT   an array A of size N
// OUTPUT  generates all the permutations of the array if called with n = N
void enumerate(int n)
{
  if(n == 1)
    do_something();//do something with A
  else {
    for(int i = 0; i < n-1; i++) {
      enumerate(n-1);
      if(n % 2 == 0)
        swap(A,i,n-1);
      else
        swap(A,0,n-1);
    }
    enumerate(n-1);
  }
}
