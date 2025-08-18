// class Solution {
// public:
//     long long minArraySum(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int>dp(n,0);
//         long long sum=0;
//        for(int i=0;i<n;i++) sum+=nums[i];
//         for (int ind = 0; ind < n; ind++) {
//          int nottake=(ind>0 ? dp[ind-1]:0);
//     int take=0;
//     int currsum=0;
//    for(int j=ind;j>=0;j--){
//     currsum+=nums[j];
//      if(currsum % k ==0){
//         take=max(take,currsum+ (j>0 ? dp[j-1]:0));
//      }
//   }
//      dp[ind]=max(nottake,take);

//         }
        
//        int deletable = dp[n - 1];
//         return sum - deletable;
        
        
//     }
// };

class Solution {
public:
    long long minArraySum(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<long long> prefix(n+1);
        for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+arr[i];
        vector<long long> dp(n+1,0);
        vector<long long> best(k,LLONG_MIN);
        best[0]=0;
        for(int i=0;i<n;i++)
        {
            if(i) dp[i]=dp[i-1];
            long long mod=prefix[i+1];
            if(best[mod%k]!=LLONG_MIN) dp[i]=max(dp[i],mod+best[mod%k]);
            best[mod%k]=max(best[mod%k],dp[i]-mod);
        }
        long long ans=prefix[n]-dp[n-1];
        return ans;
    }
};