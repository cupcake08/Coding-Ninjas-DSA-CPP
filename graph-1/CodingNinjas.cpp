const pair<int,int> dir[8] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
const string word = "CODINGNINJA";
bool validMove(int x,int y,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
}
bool dfs(vector<vector<char>> &board,int n,int m,vector<vector<int>> &vis,int wordIdx,int x,int y){
    bool found = 0;
    if(wordIdx == 11) return 1;
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int newX = x+dir[i].first;
        int newY = y+dir[i].second;
        if(validMove(newX,newY,n,m) && !vis[newX][newY] && board[newX][newY]==word[wordIdx]){
            found |= dfs(board,n,m,vis,wordIdx + 1,newX,newY);
        }
    }
    vis[x][y]=0;
    return found;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool foundPath = 0;
	vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]) foundPath = dfs(board,n,m,vis,1,i,j);
            if(foundPath) break;
        }
        if(foundPath) break;
    }
    return foundPath;
}
