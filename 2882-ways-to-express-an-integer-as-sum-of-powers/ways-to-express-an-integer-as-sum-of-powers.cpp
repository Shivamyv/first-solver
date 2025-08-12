class Solution {
public:
  int mod=1e9+7;
long long powerLL(int base, int exp) {
    long long res = 1;
    while (exp--) res *= base;
    return res;
}

int f(int ind,int sum,int x,vector<vector<int>>& dp){
   if(sum==0) return 1;
   if(sum<0) return 0;
   long long p = powerLL(ind, x);
   if (p > sum) return 0; 
   if(dp[ind][sum]!=-1) return dp[ind][sum]; 
   int take=f(ind+1,sum-p,x,dp);
   int nottake=f(ind+1,sum,x,dp);
    return dp[ind][sum]=(take+nottake) % mod;
   

}


    int numberOfWays(int n, int x) {
     
    vector<vector<int>>dp(n+2,vector<int>(n+1,-1));

      return f(1,n,x,dp);



    }
};