class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n;
        int sum = 0;

        for (int mask = 0; mask < totalSubsets; mask++) {
            int xorVal = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    xorVal ^= nums[i];
                }
            }
            sum += xorVal;
        }

        return sum;
    }
};
