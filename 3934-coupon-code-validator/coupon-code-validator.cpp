class Solution {
public:
    bool isValidCode(string &s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();

        // Business line priority
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            if (priority.find(businessLine[i]) == priority.end()) continue;

            validCoupons.push_back({priority[businessLine[i]], code[i]});
        }

        sort(validCoupons.begin(), validCoupons.end());

        vector<string> ans;
        for (auto &p : validCoupons) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
