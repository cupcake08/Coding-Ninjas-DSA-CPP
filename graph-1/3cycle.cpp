#include <bits/stdc++.h>
using namespace std;

int solve(bool **edge,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edge[i][j] && i!=j){
                for(int k=0;k<n;k++){
                    if(j!=k && k!=i && edge[j][k] && edge[i][k]){
                        count++;
                    }
                }
            }
        }
    }
    return count/6;
}

int main(){
    int n,e;
    cin>>n>>e;
    bool **edge=new bool*[n];
    for(int i=0;i<n;i++){
        edge[i]=new bool[n];
        for(int j=0;j<n;j++){
            edge[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    cout<<solve(edge,n);
}
