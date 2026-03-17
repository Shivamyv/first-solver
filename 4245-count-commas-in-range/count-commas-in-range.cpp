class Solution {
public:
    int countCommas(int n) {
      string s=to_string(n);
      int ans=1;

      if(s.size()<4) return 0;

      ans+=abs(n-1000);


   return ans;

    }
};