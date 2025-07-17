class Solution {
  int f(int ind,int prevind,int targetmod,vector<int> &nums,int k
        ,vector<vector<vector<int>>> &dp){
     int modulo=1e9+7;
  if(ind<0) return 0;

  if(dp[ind][prevind+1][targetmod+1]!=-1) return dp[ind][prevind+1][targetmod+1];
  int nottake=0+f(ind-1,prevind,targetmod,nums,k,dp);
  int take=INT_MIN;
  if(prevind==-1){
    take=1+f(ind-1,ind,-1,nums,k,dp);

  }
  else{
  int mod=(nums[prevind] + nums[ind]) % k;
  if(targetmod==-1)
  
  take=1+f(ind-1,ind,mod,nums,k,dp);
  else if(mod==targetmod)
     take=1+f(ind-1,ind,targetmod,nums,k,dp);
  }
   return  dp[ind][prevind+1][targetmod+1]=max(take,nottake) % modulo;

  }

public:
    int maximumLength(vector<int>& nums, int k) {
     int n=nums.size();
    int dp[1000][1000]={0};
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int t=(nums[i]+nums[j]) %k;
            dp[i][t]=dp[j][t]+1;
            ans=max(ans,dp[i][t]);
        }
    }
    return ans+1;

    }
};