class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     int n=nums.size();
       long long len=0;
       long long ans=0;
       for(int i=0;i<n;i++){
        if(nums[i]==0) {
            len++;
        ans+=len;
        }
        else  len=0;
       
    

     }
     return ans;

    }
};