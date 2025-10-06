class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int n=nums.size(); 
       int totalXor = 0;
        for (int x : nums) totalXor ^= x;

        if (totalXor != 0) return nums.size();

        bool allZero = true;
        for (int x : nums) if (x != 0) allZero = false;

        return allZero ? 0 : nums.size() - 1;
       


    }
};