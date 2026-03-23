class Solution {
public:
    int longestSubstring(string s, int k) {
      int n=s.size();
      int ans=0;
      unordered_map<char,int>mpp;
       for(auto it:s){
        mpp[it]++;
       }
         for(char ch:s){
            if(mpp[ch]<k){
                int maxlen=0;
                int start=0;
                for(int i=0;i<n;i++){
                    if(s[i]==ch){
                maxlen=max(maxlen,longestSubstring(s.substr(start,i-start),k));
                   start=i+1;
                    }
                }
                maxlen=max(maxlen,longestSubstring(s.substr(start),k));
                return maxlen;
            }
         }
      
       return n;

    }
};