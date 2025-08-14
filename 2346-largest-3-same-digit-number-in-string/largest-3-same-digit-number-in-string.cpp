class Solution {
public:
    string largestGoodInteger(string num) {
    string max_good = "";
    for (int i = 0; i <= (int)num.size() - 3; i++) {
        string s = num.substr(i, 3);
        if (s[0] == s[1] && s[1] == s[2]) { // all three same
            if (s > max_good) {
                max_good = s;
            }
        }
    }
    return max_good;
}
};