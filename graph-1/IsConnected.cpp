#include <bits/stdc++.h>
using namespace std;
bool isConnected(bool **edges,int n,int sv,bool *visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int curr_ele=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i]&&edges[curr_ele][i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) return false;
    }
    return true;
}
int main(){
    int n,e;
    cin>>n>>e;
    bool **edges=new bool*[n];
    for(int i=0;i<n;i++){
        edges[i]=new bool[n];
        for(int j=0;j<n;j++){
            edges[i][j]=false;
        }
    }
    //taking input of edges
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    //visited array
    bool *visited=new bool[n];
    memset(visited,false,sizeof(visited));
    //working function 
    bool ans=isConnected(edges,n,0,visited);
    ans?cout<<"true":cout<<"false";
}
