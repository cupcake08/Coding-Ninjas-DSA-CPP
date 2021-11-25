const pair<int,int> dir[4] = {{0,-1},{1,0},{0,1},{-1,0}};
bool validMove(int x,int y,int n,int m){return x>=0 && y>=0 && x<n && y<m;}
bool cycle = 0;
void dfs(vector<vector<char>> &board,vector<vector<bool>> &vis ,int n, int m,int x,int y,char needColor,int fromX = -1,int fromY=-1){
    if(board[x][y]!=needColor) return;
    if(!validMove(x,y,n,m)) return;
    if(vis[x][y]){
        cycle = 1;
        return;
    }
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int newX = x+dir[i].first;
        int newY = y+dir[i].second;
        if(newX == fromX && newY == fromY) continue;
        if(validMove(newX,newY,n,m)) dfs(board,vis,n,m,newX,newY,needColor,x,y);
    }
}
bool hasCycle(vector<vector<char>> &board, int n, int m) {
	vector<vector<bool>> vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) dfs(board,vis,n,m,i,j,board[i][j]);
    return cycle;
}
