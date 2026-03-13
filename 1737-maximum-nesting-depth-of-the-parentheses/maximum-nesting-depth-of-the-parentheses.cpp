class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
     int leftchar=0;
     int rightchar=0;
     int ans=INT_MIN;
     for(int i=0;i<n;i++){
        if(s[i]=='(') leftchar++;
        else if(s[i]==')') rightchar++;
        if(leftchar-rightchar>ans)
          ans=max(ans,leftchar-rightchar);
       }
     

     

      return ans;
    }
};