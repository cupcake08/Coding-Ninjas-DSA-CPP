#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> *DFS(bool **edges,int n,int sv,int ev,bool *visited){
    if(sv==ev){
        vector<int> *v=new vector<int>();
        v->push_back(ev);
        return v;
    }
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[sv][i]){
            vector<int> *temp=DFS(edges,n,i,ev,visited);
            if(temp!=nullptr){
                temp->push_back(sv);
                return temp;
            }
        }
    }
    return nullptr;
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
    vector<int> *ans=DFS(edges,n,start,end,visited);
    if(ans!=nullptr){
    for(int i=0;i<ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
    }
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
    delete[] visited;
}
