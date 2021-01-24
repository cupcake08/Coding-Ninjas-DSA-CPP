#include <bits/stdc++.h>
using namespace std;
/**************DFS METHOD**********************/
bool hasPathDFS(int **edges,int n,int start,int end,bool *visited){
    if(edges[start][end]) return true;
    visited[start]=true;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[start][i] && i!=start){
            if(hasPathDFS(edges,n,i,end,visited)) return true;
        }
    }
    return false;
}
/****************BFS Method***********************/
bool hasPathBFS(int **edges,int n,int start,int end,bool *visited){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int curr_ele=q.front();
        q.pop();
        if(edges[curr_ele][end]) return true;
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[curr_ele][i] && i!=curr_ele){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    //taking input of edges
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited=new bool[n];
    memset(visited,false,sizeof(visited));
    int start,end;
    cin>>start>>end;
    // bool ans=hasPathDFS(edges,n,start,end,visited);
    bool ans=hasPathBFS(edges,n,start,end,visited);
    ans?cout<<"true":cout<<"false";
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete[] edges;
    delete[] visited;
}
