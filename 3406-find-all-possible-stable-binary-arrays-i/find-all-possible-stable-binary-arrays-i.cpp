class Solution {
public:
    int M = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<long long>>> dp(
            zero+1,
            vector<vector<long long>>(one+1, vector<long long>(2,0))
        );

        for(int z=1; z<=min(zero,limit); z++)
            dp[z][0][0] = 1;

        for(int o=1; o<=min(one,limit); o++)
            dp[0][o][1] = 1;

        for(int z=1; z<=zero; z++){
            for(int o=1; o<=one; o++){

                for(int k=1; k<=min(z,limit); k++){
                    dp[z][o][0] =
                    (dp[z][o][0] + dp[z-k][o][1]) % M;
                }

                for(int k=1; k<=min(o,limit); k++){
                    dp[z][o][1] =
                    (dp[z][o][1] + dp[z][o-k][0]) % M;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % M;
    }
};