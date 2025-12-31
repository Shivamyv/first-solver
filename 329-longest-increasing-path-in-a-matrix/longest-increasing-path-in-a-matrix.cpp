class Solution {
public:
   int solve(vector<vector<int>>& matrix,int i,int j,int prevval,int n,int m,vector<vector<int>>& dp){
    if(i<0 || j<0 || i>=n|| j>=m || matrix[i][j]<=prevval) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=1;

   ans=max(ans,1+solve(matrix,i-1,j,matrix[i][j],n,m,dp));// top
   ans=max(ans,1+solve(matrix,i+1,j,matrix[i][j],n,m,dp));//down
   ans=max(ans,1+solve(matrix,i,j-1,matrix[i][j],n,m,dp));//left
   ans=max(ans,1+solve(matrix,i,j+1,matrix[i][j],n,m,dp));//right

   dp[i][j]=ans;
   return ans;

   }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
    int n=matrix.size();
    int m=matrix[0].size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
   int ans=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(dp[i][j]==-1)
            solve(matrix,i,j,-1,n,m,dp);
            ans=max(dp[i][j],ans);
        
    }
   }


    return ans;
    }
};


