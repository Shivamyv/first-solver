class Solution {
public:
  
    int f(vector<int>& nums, int k){
    int n=nums.size();
     
     int maxlen=0;
      int l=0,r=0;
     
     unordered_map<int,int>mpp;
    
    while(r<n){
    mpp[nums[r]]++;
      
  while(mpp.size()>k){
    mpp[nums[l]]--;
    if(mpp[nums[l]]==0){
        mpp.erase(nums[l]);
    }
    l++;
  }

  if(mpp.size()<=k){
    maxlen+= r-l+1;
  }
  r++;

    }
     
   return maxlen;
      
    }
      int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
      }
};