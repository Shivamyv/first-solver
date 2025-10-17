class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto &p:mpp)
        if(p.second % k==0){

            sum+= p.first *p.second;
        }
     return sum;

    }
};