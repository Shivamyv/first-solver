class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
             int tm=0;
             int delrow[]={-1,0,+1,0};
             int delcol[]={0,+1,0,-1};
             while(!q.empty()){
                auto it=q.front();
                int r=it.first.first;
                int c=it.first.second;
                int time=it.second;
               tm=max(tm,time);
               q.pop();

             for(int i=0;i<4;i++){
                 int nrow=r+delrow[i];
                 int ncol=c+delcol[i];
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                 vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                 }
             }
             }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]!=2) return -1;
        }
      }
       return tm;      
    }
};