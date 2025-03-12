class Solution {
public:
          
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
         
        int low=1,high=*max_element(nums.begin(), nums.end());;
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