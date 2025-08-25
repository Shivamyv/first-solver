class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int delrow[]={-1,0,+1,0};
       int delcol[]={0,+1,0,-1};
       vector<vector<int>>vis(n,vector<int>(m,0));
     queue<pair<int,int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               
                if ((i == 0 || j == 0 || i == n - 1 || 
                j == m - 1) && grid[i][j] == 1) { 
           
            q.push({i,j});
            vis[i][j]=1;
                }
            }
        }
            while(!q.empty()){
                int r=q.front().first;
                int c=q.front().second;
                
                q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
          if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && 
          grid[nrow][ncol]==1 
          && vis[nrow][ncol]==0){
            q.push({nrow,ncol});
            vis[nrow][ncol]=1;
          }
            }
    }
     int cnt=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                cnt++;
            }
        }
    }

       return cnt;
         


    }
};