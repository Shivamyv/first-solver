class Solution {
public:
    int beautySum(string s) { 
      int ans=0;
      int n=s.size();
       
      for(int i=0;i<n;i++){
        unordered_map<char,int>mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
          int minelement=INT_MAX;
         int maxelement=INT_MIN;
            for(auto it:mpp){
                 minelement=min(minelement,it.second);
                 maxelement=max(maxelement,it.second);
            }
            
          ans+=(maxelement-minelement);

        }
      }
    return ans;

    }
};