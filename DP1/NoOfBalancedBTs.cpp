/**
 * author: Ankit Bhankharia
**/
#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
//tabulate method(dp)
int balancedBTsDP(int n){
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]*dp[i-1])+(2*dp[i-1]*dp[i-2]);   //take care of integer overflow
    }
    return dp[n];
}
//memorisation 
int balancedBTsMem(int n,int *dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    int x=balancedBTsMem(n-1,dp);
    int y=balancedBTsMem(n-2,dp);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    int ans=(temp1+temp2)%mod;
    dp[n]=ans;
    return ans;
}
int balancedBTsMem(int n){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return balancedBTsMem(n,dp);
}
//recursion
int balancedBTs(int n) {
    if(n<=1) return 1;
    int x=balancedBTs(n-1);
    int y=balancedBTs(n-2);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    int ans=(temp1+temp2)%mod;
    return ans;
}

int main(){
    int h;
    cin>>h;
    cout<<balancedBTs(h)<<"\n";
    cout<<balancedBTsMem(h)<<"\n";
    cout<<balancedBTsDP(h);
}
