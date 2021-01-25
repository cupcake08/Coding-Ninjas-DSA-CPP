#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(bool **edge,int n,int sv,unordered_map<int,bool>& visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=1;
    vector<int> output;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        output.push_back(front);
        for(int i=0;i<n;i++){
            if(!visited[i] && edge[front][i] && i!=front){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return output;
}
void BFS(bool **edge,int n){
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> ans=BFS(edge,n,i,visited);
            sort(ans.begin(),ans.end());
            for(int j=0;j<ans.size();j++){
                cout<<ans[j]<<" ";
            }
            cout<<endl;
        }
    }
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
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    BFS(edge,n);
    //deleting dynammic memory
    for(int i=0;i<n;i++){
        delete[] edge[i];
    }
    delete[] edge;

}
