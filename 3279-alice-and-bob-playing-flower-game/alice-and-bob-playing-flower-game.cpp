class Solution {
public:
    long long flowerGame(int n, int m) {
    long long neven=n/2,meven=m/2;
    long long nodd=n-neven,modd=m-meven;
    long long res=neven*modd+nodd*meven ;   

   return res;

    }
};