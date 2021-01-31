#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
void dijkstra(int **edge,int n,bool *visited,int *dist){
        for(int i=0;i<n;i++){
            int minDist=INT_MAX;
            int vertexMinDist=-1;
            for(int j=0;j<n;j++){
                    if(!visited[j] && minDist > dist[j]){
                        minDist=dist[j];
                        vertexMinDist=j;
                    }
            }
            visited[vertexMinDist]=1;
            for(int j=0;j<n;j++){
         
                    if(!visited[j] && dist[j]>dist[vertexMinDist]+edge[vertexMinDist][j] && edge[vertexMinDist][j]>0){
                            dist[j]=dist[vertexMinDist]+edge[vertexMinDist][j];
        }
                    
}
}
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edge=new int*[n];
    for(int i=0;i<n;i++){
        edge[i]=new int[n];
        for(int j=0;j<n;j++){
            edge[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edge[f][s]=w;
        edge[s][f]=w;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int *dist=new int[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    dijkstra(edge,n,visited,dist);
    for(int i=0;i<n;i++){
            cout<<i<<" "<<dist[i]<<endl;
    }
    for(int i=0;i<n;i++){
        delete [] edge[i];
    }
    delete [] edge;
    delete [] visited;
    delete [] dist;
}
