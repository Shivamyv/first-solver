class Solution {
public:

int findMaxLen(string &an, int k, char ch) {
    int n = an.size();
    int a = 0, b = 0, count = 0, maxLen = 0;
    while (b < n) {
        if (an[b] != ch) count++;
        while (count > k) {
            if (an[a] != ch) count--;
            a++;
        }
        maxLen = max(maxLen, b - a + 1);
        b++;
    }
    return maxLen;
}

    int maxConsecutiveAnswers(string an, int k) {
         return max(findMaxLen(an, k, 'T'), findMaxLen(an, k, 'F'));
    }
};