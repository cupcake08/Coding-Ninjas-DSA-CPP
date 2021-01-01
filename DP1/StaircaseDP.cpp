#include <bits/stdc++.h>
using namespace std;
//tabulation method
long staircaseDP(long n){
    long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

//memorisation method
long staircaseMem(long n,long *dp){
    if(n<=1) return 1;
    else if(n==2) return 2;
    if(dp[n]!=-1) return dp[n]; //if small ans already exist
    long ans1=staircaseMem(n-1,dp);
    long ans2=staircaseMem(n-2,dp);
    long ans3=staircaseMem(n-3,dp);
    dp[n]=ans1+ans2+ans3;  //save the small ans
    return dp[n];  //return small ans
}
long staircaseMem(long n){
    long dp[n+1];
    memset(dp,-1,sizeof(dp));
    return staircaseMem(n,dp);
}

//recursion method
long staircaseRec(long n){
    if(n<=1) return 1;
    else if(n==2) return 2;
    long ans1=staircaseRec(n-1);
    long ans2=staircaseRec(n-2);
    long ans3=staircaseRec(n-3);
    return ans1+ans2+ans3;
}

int main(){
    long n;
    cin>>n;
    cout<<staircaseRec(n)<<"\n";
    cout<<staircaseMem(n)<<"\n";
    cout<<staircaseDP(n);
}
