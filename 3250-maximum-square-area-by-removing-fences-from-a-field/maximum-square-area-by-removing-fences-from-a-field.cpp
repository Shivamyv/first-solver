class Solution {
public:
   static const int MOD=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
      hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        // Sort fence positions
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Store all possible horizontal distances
        unordered_set<int> horizontalDistances;
        horizontalDistances.reserve(200000);

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                horizontalDistances.insert(hFences[j] - hFences[i]);
            }
        }

        // Find maximum common distance
        long long maxSide = -1;

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int dist = vFences[j] - vFences[i];
                if (horizontalDistances.count(dist)) {
                    maxSide = max(maxSide, (long long)dist);
                }
            }
        }

        // If no square is possible
        if (maxSide == -1) return -1;

        // Return area modulo 1e9+7
        return (maxSide * maxSide) % MOD;
    }
};