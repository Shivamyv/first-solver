class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
      int n=isWater.size();
      int m=isWater[0].size();
      vector<vector<int>>vis(n,vector<int>(m,0));
      vector<vector<int>>height(n,vector<int>(m,0));
      queue<pair<int,pair<int,int>>>q;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(isWater[i][j]==1){
                q.push({0,{i,j}});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }

        }
      } 
      int dr[]={-1,0,+1,0};
      int dc[]={0,+1,0,-1};

      while(!q.empty()){
        auto it=q.front();
        q.pop();
        int steps=it.first;
        int row=it.second.first;
        int col=it.second.second;
        height[row][col]=steps;
        
        for(int i=0;i<4;i++){
            int nrow=dr[i]+row;
            int ncol=dc[i]+col;
        
         if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
            q.push({steps+1,{nrow,ncol}});
            vis[nrow][ncol]=1;
         }

        }

      }


    return height;




    }
};