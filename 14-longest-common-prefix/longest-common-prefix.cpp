class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
          if(strs.empty()) return "";
          sort(strs.begin(),strs.end()); 
            string first=strs[0];
            string last=strs[n-1];
            int m = min(first.size(), last.size());
         string ans="";

        for(int i=0;i<m;i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
       return ans;
		}
};