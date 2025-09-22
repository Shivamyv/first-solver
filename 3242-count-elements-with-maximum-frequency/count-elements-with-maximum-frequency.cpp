class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        int maxi=INT_MIN;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto &p:mpp){
            maxi=max(maxi,p.second);
        }
        for(auto &p:mpp){
            if(maxi==p.second)
            ans+=p.second;
        }
        
    return ans;
   

    }
};