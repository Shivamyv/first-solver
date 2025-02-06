
class Solution {
    private:
    static bool cmp(string &s1, string &s2){
        return s1.length() < s2.length();
    }

    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size()+1)return false;
        int first = 0;
        int second = 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()){
            return true;
        }
        return false;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), cmp);

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int ind = 0; ind<n; ind++){
            for(int prev = 0; prev<ind; prev++){
                if(compare(words[ind], words[prev]) && dp[ind] < dp[prev] + 1){
                    dp[ind] = dp[prev] + 1;
                }
            }
            if(dp[ind]> maxi){
                maxi = dp[ind];
            }   
        }
        return maxi;
    }
};