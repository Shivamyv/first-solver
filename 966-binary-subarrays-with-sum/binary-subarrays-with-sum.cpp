class Solution {
public:
        int f(vector<int>& nums, int goal){
        int n=nums.size();
        if(goal < 0) return 0;
       int i=0;
       int sum=0;
      
       int cnt=0;
       for(int j=0;j<n;j++){
        sum+=nums[j];
        
        while(sum>goal){
            sum-=nums[i];
           
            i++;
       }
        cnt+=j-i+1;
         
       }
       return cnt;


    }
     int numSubarraysWithSum(vector<int>& nums, int goal) {
      return f(nums,goal)-f(nums,goal-1);  
    }

};