class Solution {
public:
  int mod=1e9+7;
long long powerLL(int base, int exp) {
    long long res = 1;
    while (exp--) res *= base;
    return res;
}


    int numberOfWays(int n, int x) {
     
    vector<int> next(n + 1, 0), curr(n + 1, 0);

       
        for (int sum = 0; sum <= n; sum++) {
            next[sum] = (sum == 0 ? 1 : 0);
        }

        
        for (int ind = n; ind >= 1; ind--) {
            long long p = powerLL(ind, x);
            for (int sum = 0; sum <= n; sum++) {
                int notTake = next[sum];
                int take = 0;
                if (p <= sum) take = next[sum - (int)p];
                curr[sum] = (take + notTake) % mod;
            }
            next = curr; 
        }

        return next[n];

    }
};