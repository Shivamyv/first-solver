class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
      int maxlen=INT_MAX;
      int index=-1;
       int hash[256]={0};
       for(char c:t){
        hash[c]++;
       }
      int l=0,r=0;
      int count=0;
      while(r<n){
          if(hash[s[r]]>0){
            count++;
          }
          hash[s[r]]--;
         
         while(count==t.size()){
         if(r-l+1<maxlen){
            maxlen=r-l+1;
            index=l;
         }
         hash[s[l]]++;
         if(hash[s[l]]>0){
            count--;
         }
         l++;
      }
      r++;

      }
      return(index==-1) ? "":s.substr(index,maxlen);
   
    }
};