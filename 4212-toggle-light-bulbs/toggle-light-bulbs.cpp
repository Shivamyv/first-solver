class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n=bulbs.size();
       vector<int>ans;
       unordered_map<int,int>mpp;
       for(auto it:bulbs){
        mpp[it]++;

       }
       for(auto ite:mpp){
        if(ite.second % 2==1){
            ans.push_back(ite.first);

        }
       }
      sort(ans.begin(),ans.end());
      return ans;


    }
};