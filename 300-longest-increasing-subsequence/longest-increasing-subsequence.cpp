class Solution {
public:
int f(int ind,int prev,vector<int>& nums,vector<vector<int>> &dp){
   int n=nums.size();
    if(ind==n) return 0;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int length=0+f(ind+1,prev,nums,dp);
    if(nums[prev]==-1||nums[ind]>nums[prev]) {
         length=max(length,1+f(ind+1,ind,nums,dp));

    }
    return dp[ind][prev+1]= length;

}
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       vector<int> dp(n,1);
       int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }

            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};