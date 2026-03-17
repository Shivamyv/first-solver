class Solution {
public:
    long long countCommas(long long n) {
      long long start=1000;
      long long ans=0;
      int commas=1;
      while(start<=n){
        long long end=start*1000-1;
        long long actualend=min(n,end);
        if(actualend>=start){
            ans+=(actualend-start+1)*commas;
        }
        start*=1000;
        commas++;
      }
    


    return ans;

    
    }
};