class Solution {
public:
    int maximumSum(vector<int>& nums) {
       int n=nums.size();
      vector<vector<int>>cnt(3);
      for(int num:nums) cnt[num % 3].push_back(num);
      for(int i=0;i<3;i++){
        sort(cnt[i].rbegin(),cnt[i].rend());
      }
      int maxsum=0;
      for(int i=0;i<3;i++){
        if(cnt[i].size()>=3){
            maxsum=max(maxsum,cnt[i][0]+cnt[i][1]+cnt[i][2]);
        }
      }
      if(cnt[0].size()>0 && cnt[1].size()>0 && cnt[2].size()>0){
        maxsum=max(maxsum,cnt[0][0]+cnt[1][0]+cnt[2][0]);
      }
      return maxsum;

    }
};