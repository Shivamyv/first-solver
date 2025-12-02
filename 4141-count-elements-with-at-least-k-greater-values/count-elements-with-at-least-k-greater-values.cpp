class Solution {
public:
    int countElements(vector<int>& nums, int k) {
       int n=nums.size();
       if(k==0) return nums.size();
       sort(nums.begin(),nums.end());
       int ans=0;
       int threshold=nums[n-k];
       for(int i=0;i<n;i++){
        if(nums[i]<threshold) ans++;

       } 
       return ans;
    }
};