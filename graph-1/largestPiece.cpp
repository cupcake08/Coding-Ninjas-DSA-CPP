const pair<int,int> dir[4] = {{-1,0},{0,-1},{1,0},{0,1}};
bool validMove(int x,int y,int n){ return x>=0 && y>=0 && x<n && y<n;}
int dfs(vector<vector<int>> &cake, int n,vector<vector<bool>> &vis,int x,int y){
    if(vis[x][y]) return 0;
    vis[x][y]=1;
    int cnt=1;
    for(int i=0;i<4;i++){
        int X = x+dir[i].first;
        int Y = y+dir[i].second;
        if(validMove(X,Y,n) && cake[X][Y]) cnt += dfs(cake,n,vis,X,Y);
    }
    return cnt;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    int mx = 0;
    vector<vector<bool>> vis(n,vector<bool>(n,0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(cake[i][j] && !vis[i][j]) mx = max(mx,dfs(cake,n,vis,i,j));
    return mx;
}
