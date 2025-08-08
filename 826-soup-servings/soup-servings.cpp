class Solution {
public:
    double P(int a, int b, vector<vector<double>> &dp) {
        if (a <= 0 && b <= 0) return 0.5; 
        if (a <= 0) return 1.0;           
        if (b <= 0) return 0.0;          
        
        if (dp[a][b] >= 0.0) return dp[a][b];
        
        return dp[a][b] = 0.25 * (
            P(a - 4, b, dp) + 
            P(a - 3, b - 1, dp) + 
            P(a - 2, b - 2, dp) + 
            P(a - 1, b - 3, dp)
        );
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0; 
        int N = (n + 24) / 25; 

        vector<vector<double>> dp(N + 1, 
        vector<double>(N + 1, -1.0));
        return P(N, N, dp);
    }
};
