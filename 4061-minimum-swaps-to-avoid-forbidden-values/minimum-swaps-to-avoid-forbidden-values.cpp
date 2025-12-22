class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
       int n=nums.size();
       int cnt=0,maxi=0;
       map<int,int>amap,bmap,matching;
       for(int i=0;i<n;i++){
        if(nums[i]==forbidden[i]){
            cnt+=(nums[i]==forbidden[i]);
            matching[nums[i]]++;
            maxi=max(maxi,matching[nums[i]]);

        }
        amap[nums[i]]++;
        bmap[forbidden[i]]++;
       }
       for(auto & p:amap){
        if(p.second > n - bmap[p.first]) return -1;

       }
        return max(maxi,(cnt+1)/2);
    }
};