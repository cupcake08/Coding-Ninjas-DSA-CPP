#include <bits/stdc++.h>
using namespace std;
const int N= 1005;
vector<int> adj[N];
vector<bool> vis(N,0);
void dfs(int v){
    vis[v]=1;
    for(auto &u:adj[v]) if(!vis[u]) dfs(u);
}
int main() {
    int v,e;
    scanf("%d %d",&v,&e);
    for(int i=0;i<e;i++){
        int f,s;
        scanf("%d %d",&f,&s);
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
    int cnt=0;
    for(int i=0;i<v;i++) if(!vis[i]) dfs(i),cnt++;
    printf("%d",cnt);
}
