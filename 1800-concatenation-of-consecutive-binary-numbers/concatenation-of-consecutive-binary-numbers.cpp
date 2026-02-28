class Solution {
public:
  int mod=1e9+7;
    int concatenatedBinary(int n) {
        long ans=0;
        int digit=0;
        for(int i=1;i<=n;i++){
         if((i &(i-1))==0) digit++;

          ans=((ans<<digit)%mod+i)%mod;

        } 
        return ans;
    }
};