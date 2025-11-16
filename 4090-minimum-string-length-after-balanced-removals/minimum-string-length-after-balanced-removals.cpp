class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int ans=0;
        int b=0;
        int cnt=0;
        int n=s.size();
      for(int i=0;i<n;i++){
        if(s[i]=='a'){
            cnt++;
        }
        else{
            b++;
        }

      

      }
      return ans=abs(cnt-b);


    }
};