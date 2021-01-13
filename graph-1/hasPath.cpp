/**
 * author: Ankit Bhankharia
**/
#include <iostream>
#include <cstring>
using namespace std;
bool hasPath(bool **edges,int n,int s,int e,bool *visited){
    if(edges[s][e]) return true;
    visited[s]=true;
    for(int i=0;i<n;i++){
        if(edges[s][i] && !visited[i]){
            if(hasPath(edges,n,i,e,visited)) return true;
        }
    }
    return false;
}
int main(){
    int n,e;  //n->vertices,e->edges
    cin>>n>>e;
    bool **edges=new bool*[n];  //edges array(2D)
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
    //call your working function below
    int start,end;
    cin>>start>>end;
    bool ans=hasPath(edges,n,start,end,visited);
    ans?cout<<"true":cout<<"false";
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
    delete[] visited;
}
