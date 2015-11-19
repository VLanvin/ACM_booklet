// INPUT   an array of data to put in the tree of size n
// OUTPUT  a binary indexed tree

int BIT[100000];
void initializeBIT(int box[],int n)//Array box[] is the given array.n is the size of the array
{
  int i,k;
  memset(BIT,0,sizeof(BIT)); //setting all elements to 0
  for(i=1;i<=n;i++)         //main loop
  {
    int value_to_be_added =box[i-1];
    k=i;
    while(k<=n)
    {
      BIT[k] +=value_to_be_added;  //adding box[i-1] to all desired positions
      k +=(k & (-k));
    }

  }
}

// Query the sum of the data from pos 1 to pos R
int query(int R,int n)
{
  int ans=0;
  int index_till =R+1;  //here R+1 is used because query is 0-based and BIT is 1-based
  while(index_till >0)
  {
    ans +=BIT[index_till];  //Pulling segments to build answer
    index_till-=(index_till & (-index_till));//getting the next desired array index
  }
  return ans;
}

// Sets the data at some index
void update(int index,int value,int n)
{
  int index_to_modify = index+1; //same reason,query is 0-based
  while(index_to_modify <=n)
  {
    BIT[index_to_modify] +=value; //modifying all the necessary locations
    index_to_modify += (index_to_modify & (-index_to_modify));
  }
}
