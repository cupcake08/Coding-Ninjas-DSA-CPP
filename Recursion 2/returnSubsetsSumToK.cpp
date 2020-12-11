int subsetSumToK(int input[], int n,int startIndex, int output[][50], int k) {
    // Write your code here
    if(startIndex==n)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }else
        {
            return 0;
        }
    }
    int smallOutput1[1000][50],smallOutput2[1000][50];
    int size1=subsetSumToK(input,n,startIndex+1,smallOutput1,k);
    int size2=subsetSumToK(input,n,startIndex+1,smallOutput2,k-input[startIndex]);
    int row=0;
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<=smallOutput1[i][0];j++)
        {
            output[row][j]=smallOutput1[i][j];
        }
        row++;
    }
    for(int i=0;i<size2;i++)
    {
        output[row][0]=smallOutput2[i][0]+1;
        output[row][1]=input[startIndex];
        for(int j=1;j<=smallOutput2[i][0];j++)
        {
            output[row][j+1]=smallOutput2[i][j];
        }
        row++;
    }
    return row;
	
}
int subsetSumToK(int input[],int n,int output[][50],int k)
{
    return subsetSumToK(input,n,0,output,k);
}
