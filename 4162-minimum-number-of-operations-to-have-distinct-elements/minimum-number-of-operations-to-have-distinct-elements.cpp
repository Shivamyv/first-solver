class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
       int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=n-1;i>=0;i--){
            mpp[nums[i]]++;
        
       
            if(mpp[nums[i]]>1){
                ans+=(i/3)+1;
               
               break;
            }
        }
            
        
        return ans; 
    }
};