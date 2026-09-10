class Solution {
public:
    void solve(vector<vector<char>>& board) {
     int n=board.size();
     int m=board[0].size();
     vector<vector<int>>vis(n,vector<int>(m,0));  
     queue<pair<int,int>>q; 
     for(int i=0;i<n;i++){
        if(board[i][0]=='O'){
            q.push({i,0});
            vis[i][0]=1;

        }
        if(board[i][m-1]=='O'){
            q.push({i,m-1});
            vis[i][m-1]=1;
        }
     }
     for(int j=0;j<m;j++){
        if(board[0][j]=='O'){
            q.push({0,j});
            vis[0][j]=1;
        }
        if(board[n-1][j]=='O'){
        q.push({n-1,j});
        vis[n-1][j]=1;
        }
     }
     int dr[]={-1,0,+1,0};
     int dc[]={0,+1,0,-1};
     while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first;
        int col=it.second;
       
       for(int k=0;k<4;k++){
        int nrow=dr[k]+row;
        int ncol=dc[k]+col;
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
          
            q.push({nrow,ncol});
            vis[nrow][ncol]=1;
        }
       }
          
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
                vis[i][j]=1;

            }
        }
     }
   



    }
};