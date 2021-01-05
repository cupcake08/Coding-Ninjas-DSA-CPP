/**
 * Author: Ankit Bhankharia
**/
#include <bits/stdc++.h>
using namespace std;
//tabulation method
int editDistanceDP(string s,string t){
    int m=s.size();
    int n=t.size();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++) dp[i]=new int[n+1];
    for(int j=0;j<=n;j++) dp[0][j]=j;   //fill 1st row
    for(int i=0;i<=m;i++) dp[i][0]=i;   //fill 1st col
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]) dp[i][j]= dp[i-1][j-1];  //check if 1st element matches
            else dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
        }
    }
    return dp[m][n];
}
//memorisation method
int editDistanceMem(string s, string t,int **dp){
    int m=s.size();
    int n=t.size();
    if(n==0 || m==0) return max(n,m);   //base case
    if(dp[m][n]!=-1) return dp[m][n];   //check if ans already exist or not
    if(s[0]==t[0]) return editDistanceMem(s.substr(1),t.substr(1),dp);
    int a=editDistanceMem(s.substr(1),t,dp);  //insert cost
    int b=editDistanceMem(s,t.substr(1),dp);  //remove cost
    int c=editDistanceMem(s.substr(1),t.substr(1),dp);//replace cost
    dp[m][n]=1+min({a,b,c});
    return dp[m][n];
}
int editDistanceMem(string s,string t){
    int **dp=new int*[s.size()+1];
    for(int i=0;i<=s.size();i++){
        dp[i]=new int[t.size()+1];
        for(int j=0;j<=t.size();j++){
            dp[i][j]=-1;
        }
    }
    return editDistanceMem(s,t,dp);
}
//recursion
int editDistanceRec(string s,string t){
    if(s.size()==0 || t.size()==0) return max(s.size(),t.size());
    if(s[0]==t[0]) return editDistanceRec(s.substr(1),t.substr(1));
    int a=editDistanceRec(s.substr(1),t);  //insert cost
    int b=editDistanceRec(s,t.substr(1));  //remove cost
    int c=editDistanceRec(s.substr(1),t.substr(1));//replace cost
    return 1+min({a,b,c});
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDistanceRec(s,t)<<"\n";
    cout<<editDistanceMem(s,t)<<"\n";
    cout<<editDistanceDP(s,t);
}
