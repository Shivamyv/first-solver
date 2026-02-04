class Solution {
public:
 long long neg=-1e18;
  long long f(int index,int status,int n,vector<int>&nums,  vector<vector<long long>> &dp){

     if(index==n)return (status==3)?0:neg;
       if(dp[index][status]!=-1) return dp[index][status];
     long long take=neg;
     long long nottake=neg;

     if(status==0) nottake=f(index+1,0,n,nums,dp);
     if(status==3) take=nums[index];
     if(index+1<n){
        if(status==0 && nums[index+1]>nums[index]){
            take=max(take,nums[index]+f(index+1,1,n,nums,dp));
        }
        else if(status==1){
            if(nums[index+1]>nums[index]){
                take=max(take,nums[index]+f(index+1,1,n,nums,dp));
            }
            else if(nums[index+1]<nums[index]){
                take=max(take,nums[index]+f(index+1,2,n,nums,dp));
            }
        }
        else if(status==2){
            if(nums[index+1]<nums[index]){
                take=max(take,nums[index]+f(index+1,2,n,nums,dp));
            }
            else if(nums[index+1]>nums[index]){
                take=max(take,nums[index]+f(index+1,3,n,nums,dp));
            }
        }
       else if(status==3 && nums[index+1]>nums[index]){
        take=max(take,nums[index]+f(index+1,3,n,nums,dp));
       }

     }
     return dp[index][status]= max(take,nottake);

     
  }
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
       vector<vector<long long>>dp(n,vector<long long>(4,-1));
     return f(0,0,nums.size(),nums,dp);



    }
};