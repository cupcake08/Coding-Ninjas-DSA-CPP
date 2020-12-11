
#include <cmath>
void printSubsetsOfArray(int arr[],int n)
{
  int count=pow(2,n);
  for(int i=0;i<count;i++)
  {
    for(int j=0;j<n;j++)
    {
      if((i&(1<<j))!=0)
      {
        cout<<arr[j]<<" ";
      }
    }
    cout<<endl;
  }
}
