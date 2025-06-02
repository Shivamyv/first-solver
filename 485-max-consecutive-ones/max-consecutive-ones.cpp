class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int mcount=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count+=1;
                mcount=max(count,mcount);
            }else{
                count=0;
            }
        }
        return mcount;
    }
};