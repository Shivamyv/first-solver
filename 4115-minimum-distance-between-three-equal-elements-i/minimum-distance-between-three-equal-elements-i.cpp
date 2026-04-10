class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return -1;
        int ans=INT_MAX;

       for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
          if(nums[j]!=nums[i]) continue;
          for(int k=j+1;k<n;k++){
            if(nums[j]==nums[k]){
                ans=min(ans,(j-i)+(k-j)+(k-i));
            }
          }

        }
       }
       if(ans==INT_MAX) return -1;
       return ans;
    }
};