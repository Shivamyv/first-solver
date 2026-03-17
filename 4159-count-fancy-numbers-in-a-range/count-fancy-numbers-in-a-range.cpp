class Solution {
public:
    string L, R;
    int n;
    long long dp[16][2][2][11][2][2][2][136];

    bool isSumMonotone (int num) {
        if (num / 10 == 0) {
            return true;
        }

        string s = to_string(num);
        if (s.size() == 2) {
            return !(s[0] == s[1]);
        }
        
        // max sum = 135
        if (s[1] > s[0] && s[2] > s[1]) return true;
        if (s[1] < s[0] && s[2] < s[1]) return true;
        return false;
    }

    long long solve (int i, int lo, int hi, int prev, bool inc, bool dec, int started, int sum) {
        if (i == n) {
            return isSumMonotone(sum) | inc | dec;
        }

        if (dp[i][lo][hi][prev + 1][inc][dec][started][sum] != -1) {
            return dp[i][lo][hi][prev + 1][inc][dec][started][sum];
        }

        int loLim = 0, hiLim = 9;
        if (lo == 1) {
            loLim = L[i] - '0';
        }

        if (hi == 1) {
            hiLim = R[i] - '0';
        }

        long long ans = 0;
        for (int d = loLim; d <= hiLim; d++) {
            int newLo = lo, newHi = hi;
            if (d != L[i] - '0') newLo = 0;
            if (d != R[i] - '0') newHi = 0;

            int newStarted = started || (d != 0);
            int newSum = sum, newPrev = prev, newInc = inc, newDec = dec;
            if (newStarted) {
                if (prev == -1) {
                    newPrev = d;
                } else {
                    if (prev < d) {
                        newDec = false;
                    } else if (prev > d) {
                        newInc = false;
                    } else {
                        newInc = false;
                        newDec = false;
                    }
                    
                    newPrev = d;
                }
                
                newSum = (sum + d);
            }

            ans += solve(i + 1, newLo, newHi, newPrev, newInc, newDec, newStarted, newSum);
        }

        return dp[i][lo][hi][prev + 1][inc][dec][started][sum] = ans;
    }
    
    long long countFancy(long long l, long long r) {
        L = to_string(l);
        R = to_string(r);
        n = R.size();

        int extra = R.size() - L.size();
        while (extra--) L = '0' + L;

        // 16 * 2 * 2 * 11 * 2 * 2 * 2 * 136
        // 5120 * 136 = 696320 = 700000 = (7 * 10^5)

        // time complexity = (7 * 10^6)
        // space complexity = (7 * 10^5)
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1, -1, true, true, 0, 0);
    }
};