class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLessEqualToGoal(nums, goal) - numSubarraysWithSumLessEqualToGoal(nums, goal - 1);
    }

 private:  
    int numSubarraysWithSumLessEqualToGoal(vector<int>& nums, int goal) {
         int n=nums.size();
      int sum=0;
       int cnt=0;
     int l=0,r=0;
     if(goal<0)
         return 0;
     while(r<n){
      sum+=nums[r];
     
     while(sum >goal){
        sum-=nums[l];
        l++;
     }
       cnt=cnt+(r-l+1);
    r++;

       }
       return cnt;
    }
};
