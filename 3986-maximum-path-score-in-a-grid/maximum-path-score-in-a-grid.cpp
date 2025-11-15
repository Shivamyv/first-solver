class Solution {
public:
static bool pathexist;
int f(int i,int j,int remaincost,int n,int m,vector<vector<int>>&grid,
 vector<vector<vector<int>>>&dp){
    if(i>=n || j>=m) return -1e8;
    if(remaincost<0) return -1e8;
    if(i==n-1 && j==m-1){
        int cell=grid[i][j];
        if(cell==0){
            pathexist=true;

            return 0;
        }
        if(cell==1 && remaincost >=1){
            pathexist=true;
            return 1;
        }
        if(cell ==2 && remaincost>=1){
            pathexist=true;
            return 2;
        }
        return -1e8;

    }
   if(dp[i][j][remaincost]!=INT_MIN){
    return dp[i][j][remaincost];
   }
   int cell=grid[i][j];
   int right,down;
   if(cell==0){
    right=f(i,j+1,remaincost,n,m,grid,dp);
    down=f(i+1,j,remaincost,n,m,grid,dp);

   }
   else if(cell==1){
     right=1+f(i,j+1,remaincost-1,n,m,grid,dp);
    down=1+f(i+1,j,remaincost-1,n,m,grid,dp);
   }
   else{
    right=2+f(i,j+1,remaincost-1,n,m,grid,dp);
    down=2+f(i+1,j,remaincost-1,n,m,grid,dp);
   }

     
  return dp[i][j][remaincost]=max(right,down);
    

}

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        pathexist=false;
     vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,
     INT_MIN)));
     int ans=f(0,0,k,n,m,grid,dp);

       return pathexist ? ans:-1;


    }
};
bool Solution::pathexist = false;