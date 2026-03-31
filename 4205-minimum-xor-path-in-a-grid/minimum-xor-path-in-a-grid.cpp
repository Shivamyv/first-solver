class Solution {
public:
  int f(int i,int j,int currxor,vector<vector<int>>& grid,vector<vector<
  vector<int>>>&dp){
    
      
       if(i==0 && j==0 ) return currxor;

       if(dp[i][j][currxor]!=-1) return dp[i][j][currxor];
        int ans=INT_MAX;
       if(i-1>=0){
         ans=min(ans,f(i-1,j,currxor^grid[i-1][j],grid,dp));
       }
       if(j-1>=0){
        ans=min(ans,f(i,j-1,currxor^grid[i][j-1],grid,dp));
       }

   return  dp[i][j][currxor]=ans;


  }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
      vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,
      vector<int>(1024,-1)));
       return f(m-1,n-1,grid[m-1][n-1],grid,dp);
    }
};