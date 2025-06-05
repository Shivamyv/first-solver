class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

   return find(nums,k)-find(nums,(k-1));
    }
    
     int find(vector<int>& nums, int k) {   
    int sum = 0;
    int count=0;
    int n = nums.size();
    if(k<0) return 0;
    int r=0,l=0;
    while(r<n){
    sum+=nums[r] %2; 

    while(sum>k){
        sum-=nums[l]%2;
        l++;
    }
    count+=r-l+1;
    r++;

  }
  return count;
     
    }
};