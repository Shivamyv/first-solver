class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int r=0,l=0;
       int n=s.size();
       int Hashlen=256;
     int hash[Hashlen];
       int maxlen=0;
       for(int i=0;i<Hashlen;i++)
       hash[i]=-1;
       while(r<n){
      if(hash[s[r]]!=-1){
        l=max(hash[s[r]]+1,l);
      }
       
    int len=r-l+1;
    maxlen=max(len,maxlen);
    hash[s[r]]=r;
    r++;
     
       }
        return maxlen;
    }
};