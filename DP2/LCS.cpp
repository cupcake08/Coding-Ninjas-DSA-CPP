/**
 * Author: Ankit Bhankharia
**/
#include <bits/stdc++.h>
using namespace std;
//tabulate method (DP)
int lcsDP(string s,string t){
    int m=s.size(),n=t.size();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++) dp[i]=new int[n+1]; //create output array
    for(int j=0;j<=n;j++) dp[0][j]=0;  //fill first row
    for(int i=0;i<=m;i++) dp[i][0]=0;  //fill first col
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
           //check if first matches
           if(s[m-i]==t[n-j]) dp[i][j]=1+dp[i-1][j-1];   
           else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
//memorisation 
int lcsMem(string s,string t,int **dp){
    if(s.size()==0 || t.size()==0) return 0;
    //check if ans already exist
    if(dp[s.size()][t.size()]!=-1) return dp[s.size()][t.size()];
    int ans;
    if(s[0]==t[0]){
        ans=1+lcsMem(s.substr(1),t.substr(1),dp);  
    } 
    else{
        int a=lcsMem(s.substr(1),t,dp);
        int b=lcsMem(s,t.substr(1),dp);
        ans= max(a,b);
    }
    dp[s.size()][t.size()]=ans;     //saving ans
    return ans;             //return answer
}
int lcsMem(string s,string t){
    int **dp=new int*[s.size()+1];
    for(int i=0;i<=s.size();i++){
        dp[i]=new int[t.size()+1];
        for(int j=0;j<=t.size();j++){
            dp[i][j]=-1;    
        }
    }
    return lcsMem(s,t,dp);
}
//recursion
int LCSRec(string s,string t){
    if(s.size() == 0 || t.size()==0) return 0;   //base case
    //recursive calls
    if(s[0]==t[0]) return 1+LCSRec(s.substr(1),t.substr(1));
    else{
        int a=LCSRec(s.substr(1),t);
        int b=LCSRec(s,t.substr(1));
        return max(a,b);
    }
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<LCSRec(s,t)<<"\n";
    cout<<lcsMem(s,t)<<"\n";
    cout<<lcsDP(s,t);
}
