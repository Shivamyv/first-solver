class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count1, count2, total;
        int n = basket1.size();
        
        for (int x : basket1) count1[x]++, total[x]++;
        for (int x : basket2) count2[x]++, total[x]++;
        
        for (auto [fruit, freq] : total) {
            if (freq % 2 != 0) return -1; 
        }

        vector<int> extra1, extra2;
        int minElem = INT_MAX;

        for (auto [fruit, _] : total) {
            int f1 = count1[fruit];
            int f2 = count2[fruit];
            int diff = abs(f1 - f2) / 2;

            if (f1 > f2) extra1.insert(extra1.end(), diff, fruit);
            else if (f2 > f1) extra2.insert(extra2.end(), diff, fruit);

            minElem = min(minElem, fruit);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        long long cost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            cost += min(2 * minElem, min(extra1[i], extra2[i]));
        }

        return cost;
    }
};
