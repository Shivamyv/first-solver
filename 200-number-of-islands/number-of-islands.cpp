class Solution {
public:
 void bfs(int i,int j,vector<vector<char>>& grid){
   int n=grid.size();
   int m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j]='0';
  
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};

   while(!q.empty()){
    auto it=q.front();
    q.pop();
    int row=it.first;
    int col=it.second;

    for(int i=0;i<4;i++){
        int nrow=row+dr[i];
        int ncol=col+dc[i];
       if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]=='1'){
         q.push({nrow,ncol});
         grid[nrow][ncol]='0';
       }

    }

   }
 }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                  cnt++;
                  bfs(i,j,grid);
                }
            }
        }
     return cnt;

    }
};