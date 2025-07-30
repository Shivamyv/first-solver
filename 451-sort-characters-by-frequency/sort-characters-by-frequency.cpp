class Solution {
public:
    string frequencySort(string s) {
     
    
     
      unordered_map<char,int>mpp;
      for( char ch: s){
        mpp[ch]++;
        
      }
     vector<pair<char,int>>freq(mpp.begin(),mpp.end());
     
        
       
         sort(freq.begin(), freq.end(),
          [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string ans = "";
        for (auto &[ch, count] : freq) {
            ans += string(count, ch);
        }
     


   return ans;

    }
};