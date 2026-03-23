class Solution {
public:
pair<long long,long long>dp[16][16];
bool vis[16][16];
 const int mod=1e9+7;

pair<long long ,long long> f(int i,int j,vector<vector<int>>& grid){
     int n=grid.size();
     int m=grid[0].size();

     
     if(i==n-1 && j==m-1) return {grid[i][j],grid[i][j]};
     
     if(vis[i][j]) return dp[i][j];
     vis[i][j]=true;
     
     long long maxi=LLONG_MIN;
     long long mini=LLONG_MAX;
     if(j+1<m){
        auto res=f(i,j+1,grid);
        long long first=grid[i][j]*res.first;
        long long second=grid[i][j]*res.second;
        maxi=max({maxi,first,second});
        mini=min({mini,first,second});

     }
     if(i+1<n){
        auto res=f(i+1,j,grid);
        long long first=grid[i][j]*res.first;
        long long second=grid[i][j]*res.second;
        maxi=max({maxi,first,second});
        mini=min({mini,first,second});

     }
     return dp[i][j]={mini,maxi};


}
    int maxProductPath(vector<vector<int>>& grid) {
      memset(vis,false,sizeof(vis));
      auto res=f(0,0,grid);

      if(res.second<0) return -1;
      return res.second % mod;
  
        

    }
};