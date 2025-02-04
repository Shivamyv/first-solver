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
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
       for(int prev=ind-1;prev >=-1;prev--){
            int length=0+dp[ind+1][prev+1];
    if(prev==-1||nums[ind]>nums[prev]) {
         length=max(length,1+dp[ind+1][ind+1]);

    }
     dp[ind][prev+1]= length;
       }
        }
        
        
        return dp[0][-1+1];

    }
};