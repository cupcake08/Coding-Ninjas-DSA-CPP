/**
 * Author: Ankit Bhankharia
**/
#include <bits/stdc++.h>
using namespace std;
//tabulation method(DP)
int minCostPathDP(int **arr,int n,int m){
    int **dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[m];
    }
    /****************INTITIALIZING DP******************/
    //fill last element of dp
    dp[n-1][m-1]=arr[n-1][m-1];
    //filling last row(right to left)
    for(int j=m-2;j>=0;j--){        //j denotes col
        dp[n-1][j]=dp[n-1][j+1]+arr[n-1][j];
    }
    //filling last col (bottom to top)
    for(int i=n-2;i>=0;i--){        //i denotes row
        dp[i][m-1]=dp[i+1][m-1]+arr[i][m-1];
    }
    /************************************************/
    //filling remaining cells
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=arr[i][j]+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
        }
    }
    return dp[0][0];
}
//memorisation method
int minCostPathMem(int **arr,int i,int j,int n,int m,int **dp){
    if(i==n-1 && j==m-1){
        return arr[i][j];
    }
    if(i>=n || j>=m-1){
        return __INT_MAX__;
    }
    if(dp[i][j]!=-1){     //check if ans already exist
        return dp[i][j];
    }
    int x=minCostPathMem(arr,i+1,j,n,m,dp);
    int z=minCostPathMem(arr,i+1,j+1,n,m,dp);
    int y=minCostPathMem(arr,i,j+1,n,m,dp);
    dp[i][j]=arr[i][j]+min({x,y,z});   //saving small ans
    return dp[i][j];   //returning small ans
}
int minCostPathMem(int **arr,int n,int m){
    int **dp=new int*[n+1];
    for(int i=0;i<n;i++){
        dp[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=-1;
        }
    }
    return minCostPathMem(arr,0,0,n,m,dp);
}
//recursive method
int minCostPath(int **a,int i,int j,int n,int m){
    if(i==n-1 && j==m-1) return a[i][j];
    if(i>=n || j>=m) return __INT_MAX__;
    int x=minCostPath(a,i+1,j,n,m);
    int y=minCostPath(a,i,j+1,n,m);
    int z=minCostPath(a,i+1,j+1,n,m);
    return a[i][j]+min({x,y,z});
}
int main(){
    int row,col;
    cin>>row>>col;
    int **a=new int*[row];
    for(int i=0;i<row;i++){
        a[i]=new int[col];  
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
    //cout<<minCostPath(a,0,0,row,col)<<"\n";
    //cout<<minCostPathMem(a,row,col)<<"\n";
    cout<<minCostPathDP(a,row,col);
    for(int i=0;i<col;i++){
        delete[] a[i];
    }
    delete [] a;
    #ifndef ONLINE_JUDGE
    int time=clock();
    cout<<"\nExecuted in : "<<double(time)/CLOCKS_PER_SEC<<endl;
    #endif
}
