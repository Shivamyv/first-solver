class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int n=nums.size();
   int cnt=0;
    for(int i=0;i<n;i++){
        
           cnt=cnt^nums[i];
        
       
    }
    return cnt;
    }
};