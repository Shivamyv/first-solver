class Solution {
public:
typedef long long  ll;
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,ll>freqcount;
       unordered_map<int,ll>sumcount;
       vector<ll>ans(n,0);
       for(int i=0;i<n;i++){
          ll freq=freqcount[nums[i]];
          ll sum=sumcount[nums[i]];
          ans[i]+=freq*i-sum;
          freqcount[nums[i]]+=1;
          sumcount[nums[i]]+=i;

       }
       freqcount.clear();
       sumcount.clear();
       for(int i=n-1;i>=0;i--){
          ll freq=freqcount[nums[i]];
          ll sum=sumcount[nums[i]];
          ans[i]+=sum-freq*i;
          freqcount[nums[i]]+=1;
          sumcount[nums[i]]+=i;
       }    
    return ans;


    }
};