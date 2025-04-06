class Solution {
public:
   void f(vector<int>&nums,int ind,int sum,vector<int>list,vector<vector<int>>& ans){
     
      if(sum==0){
        ans.push_back(list);
        return;
      }
      if(sum < 0 || ind< 0 ) return;

      f(nums,ind-1,sum,list,ans);
     list.push_back(nums[ind]);

     f(nums,ind,sum-nums[ind],list,ans);
     list.pop_back();

   }




    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
      vector<vector<int>> ans;
      vector<int>nums;
      f(candidates,candidates.size()-1,target,nums,ans);


    
        
       return ans;
        
    }
};