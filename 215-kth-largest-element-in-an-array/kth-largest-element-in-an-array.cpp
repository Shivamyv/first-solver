class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int n=nums.size();
       int ans=0;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        if((n-i)==k){
            ans=nums[i];
        }
       }
       return ans;
    }
};