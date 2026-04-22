class Solution {
public:

  bool issorted(vector<int>&nums){
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]<=nums[i-1]) return false;
    }
    return true;
  }
    bool canBeIncreasing(vector<int>& nums) {
      int n=nums.size();
   
      for(int i=0;i<n;i++){
           vector<int>ans;
           for(int j=0;j<n;j++){
            if(j!=i){
                ans.push_back(nums[j]);
            }
           }
           if(issorted(ans)) return true;;
      }
      return false;
    }
};