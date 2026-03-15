class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mpp;
       for(auto it:nums){
         mpp[it]++;
       }
       for(auto it:nums){
        if( it %2==0 && mpp[it]==1){
            return it;
        }
       }
    return -1;
    }
};