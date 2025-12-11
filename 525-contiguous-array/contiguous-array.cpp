class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int>mpp;
       int prefixsum=0;
       mpp[0]=-1;
       int ans=0;
       for(int i=0;i<n;i++){
        if(nums[i]==1) prefixsum+=1;
        else{
            prefixsum-=1;
        }
        if(mpp.count(prefixsum)){
            ans=max(ans,i-mpp[prefixsum]);
        }
        else{
            mpp[prefixsum]=i;
        }
       }

       return ans;
         

    }
};