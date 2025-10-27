class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
     int n=nums.size();
     long long ans=0;
     for(int i=0;i<n;i++){
        if(nums[i]<0) nums[i]=-nums[i];
     }
     sort(nums.begin(),nums.end());
     int i=0,j=n-1;
     while(i<j){
        ans+=nums[j]*nums[j];
        ans-=nums[i]*nums[i];
        i++;
        j--;
     }
     
     if(n% 2==1){
        ans+=nums[n/2]*nums[n/2];
     }
     
      return ans;
      
    }
};