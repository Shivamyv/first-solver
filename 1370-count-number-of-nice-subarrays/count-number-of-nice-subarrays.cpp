class Solution {
public:
int f(vector<int>& nums, int k){
     int n=nums.size();
     if(k<0) return 0;
        int l=0;
        int ans=0;
        int sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r]%2;

         while(sum>k){
            sum-=nums[l]%2;
            l++;
         }
         ans+=(r-l+1);
        }
        return ans;
    
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};