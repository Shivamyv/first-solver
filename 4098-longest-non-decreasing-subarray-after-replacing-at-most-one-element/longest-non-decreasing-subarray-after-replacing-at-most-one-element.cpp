class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int sz = size(nums);
      vector<int> dp1(sz, 1), dp2(sz, 1);
      dp1[0] = 0;
      for(int i = 2;i < sz; ++i) {
        if(nums[i - 1] >= nums[i - 2])
          dp1[i] = dp1[i - 1] + 1;
      }

      dp2[sz - 1] = 0;
      for(int i = sz - 3;i >= 0; --i) {
        if(nums[i + 1] <= nums[i + 2])
          dp2[i] = dp2[i + 1] + 1;
      }

      int maxLen = 0;
      for(int i = 0;i < sz; ++i) {
        // either first, last or in b/w & previous <= next of i
        if(i == 0 || i == sz - 1 || nums[i - 1] <= nums[i + 1])
          maxLen = max(maxLen, dp1[i] + dp2[i] + 1);
        else {
          // pick either left or right
          maxLen = max({maxLen, 1 + dp1[i], 1 + dp2[i]});
        }
      }
      return maxLen;
    }
};