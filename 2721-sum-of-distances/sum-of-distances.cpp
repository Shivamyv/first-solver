class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans(n,0);
       unordered_map<int,vector<int>>mpp;
       for(int i=0;i<n;i++){
         mpp[nums[i]].push_back(i);
       }
       for(auto it:mpp){
       vector<int>current=it.second;
        int idx=current.size();
        vector<long long>prefix(idx,0);
        prefix[0]=current[0];
        for(int i=1;i<idx;i++){
            prefix[i]=prefix[i-1]+current[i];
        }

        for(int i=0;i<idx;i++){
            int index=current[i];

            long long left=0;
            if(i>0){
                left=(long long)i*current[i]-prefix[i-1];
            }

            long long right=0;
            if(i<idx-1){
                right=(prefix[idx-1]-prefix[i])-(long long)(idx-i-1)*
                current[i];
            }
            ans[index]=left+right;
        }
       
       }
       
      
   return ans;



    }
};