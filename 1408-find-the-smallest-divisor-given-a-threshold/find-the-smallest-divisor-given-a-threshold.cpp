class Solution {
public:
          int maxelement(vector<int>& nums){
            int n=nums.size();
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                maxi=max(maxi,nums[i]);
            }
            return maxi;
          }
          int f(vector<int>& nums,int threshold){
            int n=nums.size();
            
            int cnt=0;
            for(int i=0;i<n;i++){
             cnt+=ceil((double)(nums[i])/(double)threshold);
            }
            return cnt;
          }
     
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
      
        int low=1,high=maxelement(nums);
        while(low<=high){
            int mid=(low+high)/2;
           if(f(nums,mid) <=threshold){
            high=mid-1;
           }
           else{
            low=mid+1;
           }
        }
        return low;
    }
};