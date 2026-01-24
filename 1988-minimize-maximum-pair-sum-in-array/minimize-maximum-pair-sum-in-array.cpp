class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int ans=0;
       
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<j){
            ans=nums[i]+nums[j];
            i++;
            j--;
            if(maxi<ans){
                maxi=ans;
                
            }
   
        }

    return maxi;

    }
};