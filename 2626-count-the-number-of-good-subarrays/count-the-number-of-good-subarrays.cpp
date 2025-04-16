class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long total = 0, pairs = 0;
        int n = nums.size(), left = 0;

        for (int right = 0; right < n; right++) {
            int num = nums[right];
            pairs += mp[num];  // Add existing occurrences as pairs
            mp[num]++;
            
            // While pairs condition is met, count all valid subarrays ending at right
            while (pairs >= k) {
                total += n - right;
                mp[nums[left]]--;
                pairs -= mp[nums[left]];
                left++;
            }
        }

        return total;
    }
};