class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       vector<int>ans;
       int n=nums.size();
       sort(nums.begin(),nums.end());
        
       unordered_set<int>present(nums.begin(),nums.end());
        int i=nums[0],j=nums[n-1];
            for(int k=i;k<=j;k++){
           if(present.find(k)==present.end()){
            ans.push_back(k);
           }
         
        
          

        }
        sort(ans.begin(),ans.end());
       return ans;


    }
};