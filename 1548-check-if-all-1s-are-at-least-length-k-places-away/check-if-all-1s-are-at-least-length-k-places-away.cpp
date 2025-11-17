class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int previndex=-1;
      
        for(int i=0;i<n;i++){
            if(nums[i]==1){
        if(previndex !=-1 && i-previndex-1<k){
           return false;
        }
       previndex=i;
          
        }
        }
          return true;

    }
};