class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int diff=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                diff=min(diff,abs(i-start));
            }
        }
        return diff;
    }
};