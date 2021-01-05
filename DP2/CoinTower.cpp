#include <bits/stdc++.h>
using namespace std;
string findWinner(int n,int x,int y){
    if(x>y) swap(x,y);
    bool dp[n+1];
    for(int i=1;i<=n;i++){
        if(i==1||i==x||i==y) dp[i]=true;
        else if(i<x) dp[i]=!dp[i-1];
        else if(i<y) dp[i]=!dp[i-x];
        else dp[i]=!(dp[i-1]&&dp[i-x]&&dp[i-y]);
    }
    if(dp[n]) return "Beerus";
    else return "Whis";
}
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    cout<<findWinner(x,y,z);
}
