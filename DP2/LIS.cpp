#include <bits/stdc++.h>
using namespace std;
//tabualate method
int longestIncreasingSubsequenceDP(int *arr,int n){
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                if(dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    int best=0;
    for(int i=0;i<n;i++){
        if(best < dp[i]) best=dp[i];
    }
    return best;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<longestIncreasingSubsequenceDP(a,n);
}
