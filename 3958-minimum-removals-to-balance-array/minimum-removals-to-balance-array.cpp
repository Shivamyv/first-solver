class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
       
       int maxlen=0;
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<n;i++){
        while(j<n && (long long)nums[i]*k >= (long long)nums[j]){
           j++;


            }

              maxlen=max(maxlen,j-i); 
            
           
            
        }
        return n-maxlen;
    }
};