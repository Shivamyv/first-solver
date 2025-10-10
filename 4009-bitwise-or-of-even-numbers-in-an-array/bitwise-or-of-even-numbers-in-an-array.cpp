class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
        if(nums[i]% 2==0){
            ans.push_back(nums[i]);
        }
        for(int j=0;j<ans.size();j++){
            cnt |=ans[j];
        }


        }
     return cnt;

    }
};