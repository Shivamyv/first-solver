class Solution {
public:
    int residuePrefixes(string s) {
         int n=s.size();
        int ans=0;
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            if((i+1)%3==(int)st.size()){
                ans+=1;
            }
           
        }
      return ans;
    }
};