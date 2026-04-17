class Solution {
public:
  int getreverse(int n){
       int rev=0;
       while(n>0){
        int rem=n%10;
        rev=rev*10+rem;
        n/=10;
   
       }
       return rev;
  }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mpp.count(nums[i])){
                ans=min(ans,i-mpp[nums[i]]);
            }

        mpp[getreverse(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;


    }
};