class Solution {
public:
 int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        for(int i=0;i<queries.size();i++){
             int l=queries[i][0]; 
             int r=queries[i][1];
             int k=queries[i][2];
             int v=queries[i][3];
           
             int idx=l;
             while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%mod;
                idx+=k;
             }  
           
            
        }
        int result=0;
        for(int num:nums){
            result^=num;
        }
        
     return result;

    }
};