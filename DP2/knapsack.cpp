/**
  Author: Ankit Bhankharia
**/
#include <bits/stdc++.h>
using namespace std;
//tabulation method (DP)
int knapsackDP(int *weights,int *val,int n,int w){
    int dp[n+1][w+1];
    for(int j=0;j<=w;j++) dp[0][j]=0;  //fill 1st row
    for(int i=0;i<=n;i++) dp[i][0]=0;   //fill 1st col
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weights[i-1]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(val[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][w];
}
//memoization
int knapsackMem(int *weights, int *val, int n, int w, int **dp)
{
    if (n == 0 || w == 0) return 0;  
    if(dp[n][w]!=-1) return dp[n][w];
    int ans;
    if (weights[0] > w)
        ans = knapsackMem(weights + 1, val + 1, n - 1, w, dp);
    else{
        int x = knapsackMem(weights + 1, val + 1, n - 1, w, dp);
        int y = knapsackMem(weights + 1, val + 1, n - 1, w - weights[0], dp) + val[0];
        ans = max(x, y);
    }
    dp[n][w]=ans;
    return ans; 
}
int knapsackMem(int *weights, int *val, int n, int m)   
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    return knapsackMem(weights, val, n, m, dp);
}
//recursive
int knapsackRec(int *weights, int *val, int n, int w)
{
    if (n == 0 || w == 0)
        return 0;
    if (weights[0] > w) return knapsackRec(weights + 1, val + 1, n - 1, w);
    int x = knapsackRec(weights + 1, val + 1, n - 1, w);
    int y = knapsackRec(weights + 1, val + 1, n - 1, w - weights[0]) + val[0];
    return max(x, y);
}

int main()
{
    int n;
    cin >> n;
    int weights[n];
    for (int i = 0; i < n; i++) cin >> weights[i];
    int val[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    int w;
    cin >> w;
    cout << knapsackRec(weights, val, n, w) << "\n";
    cout << knapsackMem(weights, val, n, w) << "\n";
    cout<<knapsackDP(weights,val,n,w);
}
