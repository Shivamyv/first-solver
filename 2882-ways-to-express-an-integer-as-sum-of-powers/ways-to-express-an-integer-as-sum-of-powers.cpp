class Solution {
public:
  int mod=1e9+7;
long long powerLL(int base, int exp) {
    long long res = 1;
    while (exp--) res *= base;
    return res;
}


    int numberOfWays(int n, int x) {
     
    vector<vector<int>>dp(n+2,vector<int>(n+1,0));
      for(int ind=1;ind<=n+1;ind++){
        dp[ind][0]=1;
      }
      
     
     
     for (int ind = n; ind >= 1; ind--) {
       long long p = powerLL(ind, x);
      for (int sum = 0; sum <= n; sum++) {


        int notTake = dp[ind + 1][sum];
                int take = 0;
                if (p <= sum) take = dp[ind + 1][sum - p];
     dp[ind][sum]=(take+notTake) % mod;
   
     

     }
     }
     return dp[1][n];

    }
};