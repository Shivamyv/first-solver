class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
    int n=nums.size();
    
    int smaller=0,largest=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<k;i++){
        smaller+=nums[i];

    }
    for(int j=n-1;j>=0;j--){
        largest+=nums[j];
        k--;
        if(k==0){
            break;
        }
    }
    
   return abs(largest-smaller);
     
    }
};