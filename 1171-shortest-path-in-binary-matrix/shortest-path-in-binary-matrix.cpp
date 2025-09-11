class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
      
      if(grid[0][0]==1 || grid[n-1][n-1]==1)
      return -1;      
     
      vector<vector<int>> dist(n,vector<int>(n,1e9));
      dist[0][0]=1;
       queue<pair<int,int>>q; 
     
      q.push({0,0});
     int dr[]={-1,-1,0,+1,+1,+1,0,-1};
     int dc[]={0,+1,+1,+1,0,-1,-1,-1};
     while(!q.empty()){
       auto it=q.front();
       q.pop();
      
       int r=it.first;
       int c=it.second;
        int dis=dist[r][c];
         if (r == n-1 && c == n-1) return dis;
      for(int i=0;i<8;i++){
        int nrow=r+dr[i];
        int ncol=c+dc[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && 
        grid[nrow][ncol]==0 && dis+1 < dist[nrow][ncol] ){
            dist[nrow][ncol]=dis+1;
            
            
            q.push({nrow,ncol});
        }

      }

     }
     return -1;
        
    }
};