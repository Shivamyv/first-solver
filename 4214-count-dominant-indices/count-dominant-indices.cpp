class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
      int ans=0;
        vector<int>suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=nums[i]+suffix[i+1];
        }
   for(int i=0;i<n-1;i++){
   
        if(nums[i]>(suffix[i+1]/(n-i-1))){
        ans++;
        
    }
   }
     return ans;
    }
};