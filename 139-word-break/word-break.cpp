#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        dp[0] = true; 

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                std::string word = s.substr(j, i - j);
                for (int k = 0; k < wordDict.size(); ++k) {
                    if (dp[j] && wordDict[k] == word) {
                        dp[i] = true;
                        break;
                    }
                }
                if (dp[i]) break;
            }
        }

        return dp[n];
    }
};

