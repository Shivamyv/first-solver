class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long tvalue=0;
        long long value=0;
        int n=nums.size();
       
       sort(nums.begin(),nums.end());
       int i=nums[0];
       int j=nums[n-1];
       value=j-i;
       tvalue=k*value;
       return tvalue;

    }
};