void helper(int arr[],int n,int k,int out[],int m)
{
    if(n==0)
    {
        if(k==0)
        {
            for(int i=0;i<m;i++)
            {
                cout<<out[i]<<" "; 
            }
            cout<<endl;
            return;
        }
        return;
    }
    
    int newarray[m+1];
    int i;
    for(i=0;i<m;i++)
    {
        newarray[i]=out[i];
    }
    newarray[i]=arr[0];
    helper(arr+1,n-1,k-arr[0],newarray,m+1);
    helper(arr+1,n-1,k,out,m);
    
    
}
void printSubsetSumToK(int input[], int size, int k) {
    int out[10000];
    helper(input,size,k,out,0);
}
