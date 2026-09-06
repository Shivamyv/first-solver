class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
       int n=nums.size();
       long long firstsum=0;
       long long totalsum=0;
       int half=n/2;
      int ans=0;
     
       for(int i=0;i<n;i++){
        totalsum+=nums[i];
       } 
       for(int i=0;i<half;i++){
        firstsum+=nums[i];
       }
       for(int i=0;i<n;i++){
        if(firstsum > totalsum-firstsum){
            ans++;
        }
        firstsum-=nums[i];
        firstsum+=nums[(i+half)%n];
       }
       return ans;
    
    }
};