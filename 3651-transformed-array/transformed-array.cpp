class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
      
       int n=nums.size();
       int newindex=0;
      vector<int>ans;
      
       for(int i=0;i<n;i++){
       
       if(nums[i]==0){
        ans.push_back(nums[i]);

       }
        else {
            newindex=((i+nums[i])%n+n)%n;
         ans.push_back(nums[newindex]);
       }
       }

    return ans;

    }
};