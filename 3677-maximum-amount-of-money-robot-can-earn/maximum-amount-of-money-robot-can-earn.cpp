class Solution {
public:
int f(int i,int j,vector<vector<int>>& coins,          
      vector<vector<vector<int>>>&dp,int k){
      int m=coins.size();
      int n=coins[0].size();
      if(i==m-1 && j==n-1){
        if(coins[i][j]<0 && k>0){
         return 0;
        }
        return coins[i][j];
      }
      if(i>=m || j>=n) return INT_MIN;

      
      if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
      
        int take=coins[i][j]+max(f(i+1,j,coins,dp,k),f(i,j+1,coins,dp,k));
       int skip=INT_MIN;
       
       if(coins[i][j]<0 && k>0){
        int skipright=f(i+1,j,coins,dp,k-1);
        int skipleft=f(i,j+1,coins,dp,k-1);
        skip=max(skipright,skipleft);
       }
      return dp[i][j][k]=max(take,skip);
      }

    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,
        vector<int>(3,INT_MIN)));
        return f(0,0,coins,dp,2);
    }
};