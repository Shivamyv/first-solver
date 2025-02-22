class Solution {
public:
    int maximumCount(vector<int>& nums) {
      int n=nums.size();
     int cnt=0;
     int low=0,high=0;
      for(int i =0;i<n;i++){
        if(nums[i]<0) {
            low++;
        }
        else if (nums[i]>0){
        high++;
        }
        cnt=max(low,high);
      }
            
        
      return cnt;
    }
};