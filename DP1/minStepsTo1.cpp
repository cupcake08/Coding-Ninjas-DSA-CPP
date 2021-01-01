#include <bits/stdc++.h>
using namespace std;
//tabulate method(DP)
int minStepsTo1DP(int n){
    int dp[n+1];
    dp[0]=0;  //only dp[1] is enough
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int x=dp[i-1];
        int y=__INT_MAX__,z=__INT_MAX__;
        if(i&1==0) y=dp[i>>1];  //change bitwise operators to operational operators for all test cases to pass
        if(i%3==0) z=dp[i/3];
        dp[i]=1+min({x,y,z});
    }
    return dp[n];
}

//memorisation method (DP)
int minStepTo1Mem(int n,int *dp){
    if(n<=1) return 0;
    if(dp[n]!=-1) return dp[n]; //ans already exist
    int x=minStepTo1Mem(n-1,dp);
    int y=__INT_MAX__,z=__INT_MAX__;
    if(n&1 == 0) y=minStepTo1Mem(n>>1,dp);
    if(n%3==0) z=minStepTo1Mem(n/3,dp);
    dp[n]=1+min({x,y,z});
    return dp[n];
}
int minStepTo1Mem(int n){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return minStepTo1Mem(n,dp);
}
//recursion method(Brute Force)
int minStepTo1Rec(int n){
    if(n<=1) return 0;  //base case
    int x=minStepTo1Rec(n-1);
    int y=__INT_MAX__,z=__INT_MAX__;
    if(n&1 == 0) y=minStepTo1Rec(n>>1);
    if(n%3==0) z=minStepTo1Rec(n/3);
    return 1+min(x,min(y,z));
}

int main(){
    int n;
    cin>>n;
    cout<<minStepTo1Rec(n)<<endl;
    cout<<minStepTo1Mem(n)<<endl;
    cout<<minStepsTo1DP(n);
}
