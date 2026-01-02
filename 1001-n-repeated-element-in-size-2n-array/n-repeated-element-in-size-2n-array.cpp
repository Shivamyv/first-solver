class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto iter: mpp){
            if(iter.second >1){
                ans=iter.first;
            }
        }
        return ans;
    }
};