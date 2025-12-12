class Solution {
public:
  bool isprime(int n){
    if(n % 2==0) return false;
    for(int i=3;i*i<=n;i+=2){
        if(n % i==0) return false;
    }
    return true;
  }
    int largestPrime(int n) {
        if(n==1) return 0;
        int ans=2,m=3,sum=2;
        while(sum+m<=n){
            if(isprime(m)){
                sum+=m;
                if(isprime(sum)) ans=sum;
            }
            m+=2;
        }
        return ans;
    }
};