class Solution {
public:
  void f(int ind,vector<int> &temp,vector<int>& nums,vector<vector<int>>& ans){
    if(ind==nums.size()){
        ans.push_back(temp);
        return;
    }
     temp.push_back(nums[ind]);
    f(ind+1,temp,nums,ans);
    temp.pop_back();
    for(int j=ind+1;j<nums.size();j++){
      if(nums[j]!=nums[ind]){
         f(j,temp,nums,ans);
         return;
      }
    }

    f(nums.size(),temp,nums,ans);

   }
  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        f(0,temp,nums,ans);
        return ans;
    }
};