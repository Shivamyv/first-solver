class Solution {
public:
static const int mod=1e9+7;
int solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>&dp){
      
      if(dp[i][j]!=-1) return dp[i][j];
      long long ans=1;
     

    int delrow[4]={-1,0,+1,0};
    int delcol[4]={0,+1,0,-1};

    for(int d=0;d<4;d++){
        int in=i+delrow[d];
        int jm=j+delcol[d];
       if(in>=0 && jm>=0 && in<n && jm<m && grid[in][jm]> grid[i][j]){
        ans=(ans+solve(grid,in,jm,n,m,dp)) % mod;
       }


    }
    dp[i][j]=ans;
    return dp[i][j] ;
}

   
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
      
        vector<vector<int>>dp(n,vector<int>(m,-1));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
        ans=(ans+solve(grid,i,j,n,m,dp)) % mod;
            
            
            
            
        }
       }
       return ans ;

    }
};