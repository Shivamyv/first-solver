class Solution {
public:
    int findMin(vector<int>& nums) {
     int n=nums.size();
     int cnt=INT_MAX;
       for(int i=0;i<n;i++){
        if(nums[i]<cnt){
            cnt=nums[i];
        }   
           }
           return cnt; 
    }
};