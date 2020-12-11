int subset(int arr[],int n,int output[][20],int si=0)
{
  if(si==n)
  {
    output[0][0]=0;
    return 1;
  }
  int smallSize=subset(arr,n,output,si+1);
  for(int i=0;i<smallSize;i++)
  {
    output[i+smallSize][0]=output[i][0]+1;
    output[i+smallSize][1]=arr[si];
    for(int j=1;j<=output[i][0];j++)
    {
      output[i+smallSize][j+1]=output[i][j];
    }
  }
  return (2*smallSize);
}
