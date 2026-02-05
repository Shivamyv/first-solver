class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int,int>>freq(mpp.begin(),mpp.end());
        sort(freq.begin(),freq.end(),[](auto &a,auto &b){
        return a.second>b.second;
    });
          for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
        }


       return ans; 
}
    
};