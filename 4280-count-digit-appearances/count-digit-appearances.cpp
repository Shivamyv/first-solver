class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
          if(nums[i]==0 && digit==0) {
            ans++;
          continue;
          }
          while(nums[i]>0){
            if(nums[i]%10==digit){
                ans++;
            }
            nums[i]/=10;
          }
        }
        return ans;

    }
};