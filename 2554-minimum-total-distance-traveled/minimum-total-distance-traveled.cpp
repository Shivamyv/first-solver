class Solution {
public:
     long long f(int i,int j,vector<int>& robot, vector<vector<int>>&
        factory,vector<vector<long long>>&dp){
       int n=robot.size();
       int m=factory.size();
       if(i==n) return 0;
       if(j==m) return 1e15;
       if(dp[i][j]!=-1) return dp[i][j];
       long long res=f(i,j+1,robot,factory,dp);

       long long cost=0;
       int pos=factory[j][0];
       int limit=factory[j][1];

       for(int k=0;k<limit && i+k<n;k++){
        cost+=abs(robot[i+k]-pos);
        res=min(res,cost+f(i+k+1,j+1,robot,factory,dp));
       }
     return dp[i][j]=res;

        }


    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>&
          factory) {
        int n=robot.size();
        int m=factory.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
       vector<vector<long long>>dp(n,vector<long long>(m,-1));
       return f(0,0,robot,factory,dp);








        
    }
};