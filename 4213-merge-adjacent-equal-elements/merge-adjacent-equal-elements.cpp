class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>ans;
        int n=nums.size();
        for( const auto &it:nums){
           long long cur=it;
            while(!ans.empty() && ans.back()==cur){
               cur*=2;
                ans.pop_back();
            }
            ans.push_back(cur);
        }
          return ans;     
        
    }
};