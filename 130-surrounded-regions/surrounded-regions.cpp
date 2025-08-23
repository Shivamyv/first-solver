class Solution {
public:
void bfs(int row,int col,vector<vector<char>>&vis,vector<vector<char>>&board,int delrow[],int delcol[]){
 int n=board.size();
 int m=board[0].size();
 queue<pair<int,int>>q;
 q.push({row,col});
 vis[row][col]=1;
 while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
        int nrow=r+delrow[i];
        int ncol=c+delcol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && 
        board[nrow][ncol]=='O' && !vis[nrow][ncol]){
             vis[nrow][ncol]=1;
            q.push({nrow,ncol});

        }
    }
 }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
         int delrow[]={-1,0,+1,0};
         int delcol[]={0,+1,0,-1};
        vector<vector<char>>vis(n,vector<char>(m,0));
        
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && board[0][j] == 'O')
                bfs(0, j, vis, board, delrow, delcol);
            
            if(!vis[n-1][j] && board[n-1][j] == 'O')
                bfs(n-1, j, vis, board, delrow, delcol);
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && board[i][0] == 'O')
                bfs(i, 0, vis, board, delrow, delcol);

            if(!vis[i][m-1] && board[i][m-1] == 'O')
                bfs(i, m-1, vis, board, delrow, delcol);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};