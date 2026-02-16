class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq,freqcount;
        for(auto it:nums){
            freq[it]++;
        }
        for(auto &ite:freq){
            freqcount[ite.second]++;
        }
       for(auto x:nums){
        if(freqcount[freq[x]]==1){
            return x;
        }
       }
      return -1;
    }
};