#include <bits/stdc++.h>
using namespace std;
//tabulate method(DP)
int minCountDP(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=__INT_MAX__;
        for(int j=0;j*j<=i;j++){
            dp[i]=min(dp[i],dp[i-(j*j)]);
        }
        dp[i]++;
    }
    return dp[n];
}
//memorisation method
int minCount(int n,int *dp){  //helper function
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];  //check if small ans id already calculated
    int ans=__INT_MAX__;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,minCount(n-(i*i),dp));
    }
    dp[n]=ans+1;  //saving the small ans
    return dp[n]; //return the ans
}
int minCountMem(int n){ 
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return minCount(n,dp);
}
//recursive Method
int minCountRec(int n){
    if(n<=1) return n;
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,minCountRec(n-(i*i)));
    }
    return ans+1;
}
//sample input= 12
//sample output = 3
int main(){
    int n;
    cin>>n;
    cout<<minCountRec(n)<<"\n";
    cout<<minCountMem(n)<<"\n";
    cout<<minCountDP(n);
}
