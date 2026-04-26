class Solution {
public:
  bool bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<tuple<int,int,int,int>>q;
        q.push({i,j,-1,-1});
        vis[i][j]=true;
        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};
        
        while(!q.empty()){
         auto [row,col,prevrow,prevcol]=q.front();
         q.pop();
           
           for(int k=0;k<4;k++){
             int nrow=row+dr[k];
             int ncol=col+dc[k];
           
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==  
           grid[row][col]){
               if(nrow==prevrow && ncol==prevcol) continue;
               if(vis[nrow][ncol]) return true;
               vis[nrow][ncol]=true;
                q.push({nrow,ncol,row,col});
                
             }

        }
        }
        return false;


      }
      bool containsCycle(vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<bool>>vis(n,vector<bool>(m,false));
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(!vis[i][j] && bfs(i,j,grid,vis)) return true;
            }
          }
        return false;

    }
};