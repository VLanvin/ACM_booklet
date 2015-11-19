// INPUT   a string s of length n
// OUTPUT  an array p[2][n] such that :
//           - p[0][i] = j iff s[i-j+1..i+j-1] is palindromic (odd length)
//           - p[1][i] = j iff s[i-j..i+j-1] is palindromic (even length)
vector<vector<int>> p(2,vector<int>(n,0));
for(int z=0,l=0,r=0;z<2;z++,l=0,r=0) 
{
  for(int i=0;i<n;i++)
  {
    if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
    int L=i-p[z][i], R=i+p[z][i]-!z;
    while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
    if(R>r) l=L,r=R;
  }
}
