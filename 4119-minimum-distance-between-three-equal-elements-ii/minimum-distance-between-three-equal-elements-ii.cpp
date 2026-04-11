class Solution {
public:
    int minimumDistance(vector<int>& nums) {
      int n=nums.size();
      int result=INT_MAX;
     unordered_map<int,vector<int>>mpp;
      for(int k=0;k<n;k++){
        mpp[nums[k]].push_back(k);
        if(mpp[nums[k]].size()>=3){
            vector<int>&vec=mpp[nums[k]];
            int siz=vec.size();
            int i=vec[siz-3];
            result=min(result,(k-i));
        }
      }

       return result==INT_MAX?-1:2*result;



    }
};