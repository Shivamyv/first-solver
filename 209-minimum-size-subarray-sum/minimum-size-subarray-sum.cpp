class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n=nums.size();
      int length=INT_MAX;
      int sum=0;
      int r=0,l=0;
     while(r<n){
         sum+=nums[r];
        r++;
      
      while(sum>=target){
        length=min(length,r-l);
        sum-=nums[l];
         l++;
      }
     

     }
     if(length==INT_MAX) return 0;
     else
     return length;

    }
};