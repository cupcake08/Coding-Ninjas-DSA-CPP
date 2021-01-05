/**
 Author : Ankit Bhankharia
**/
#include <bits/stdc++.h>
using namespace std;
//tabulation method
int maxMoneyLootedDP(int *arr,int n){
    int dp[n];
    dp[0]=arr[0]; //initialize dp
    dp[1]=max(arr[1],dp[0]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    return dp[n-1];
}

//recursive  (TLE)
int maxMoneyLooted(int *arr,int n){
    //base case
    if(n==0) return 0;
    else if(n==1) return arr[0];
    //recursive call
    int ans=maxMoneyLooted(arr+1,n-1);  //excluding current
    int ans2=maxMoneyLooted(arr+2,n-2)+arr[0];  //including current
    //small calculation
    return max(ans,ans2);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<maxMoneyLooted(a,n)<<endl;
    cout<<maxMoneyLootedMem(a,n)<<endl;
    cout<<maxMoneyLootedDP(a,n);
}
