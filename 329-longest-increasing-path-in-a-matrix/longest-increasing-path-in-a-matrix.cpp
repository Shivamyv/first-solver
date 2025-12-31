class Solution {
public:
   int solve(vector<vector<int>>& matrix,int i,int j,int prevval,int n,int m,vector<vector<int>>& dp){
    if(i<0 || j<0 || i>=n|| j>=m || matrix[i][j]<=prevval) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=1;
   int delrow[4]={-1,0,+1,0};
   int delcol[4]={0,+1,0,-1};
   for(int d=0;d<4;d++){
    int ni=i+delrow[d];
    int nj=j+delcol[d];
    ans=max(ans,1+solve(matrix,ni,nj,matrix[i][j],n,m,dp));
   }


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


