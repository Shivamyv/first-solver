class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
        if(grid[i][0]==1){
            q.push({i,0});
            vis[i][0]=1;

        }
        if(grid[i][m-1]==1){
            q.push({i,m-1});
            vis[i][m-1]=1;
        }
     }
     for(int j=0;j<m;j++){
        if(grid[0][j]==1){
            q.push({0,j});
            vis[0][j]=1;
        }
        if(grid[n-1][j]==1){
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
        for(int i=0;i<4;i++){
            int nrow=dr[i]+row;
            int ncol=dc[i]+col;

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && 
            grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
     }
     int ans=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !vis[i][j]) ans++;
        }
     }
      return ans;    

    }
};