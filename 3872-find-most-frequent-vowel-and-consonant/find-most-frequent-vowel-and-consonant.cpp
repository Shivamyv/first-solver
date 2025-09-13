class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        unordered_map<char,int> vowelFreq, consFreq;

        for(char c : s){
            if(vowels.count(c)){
                vowelFreq[c]++;
            } else {
                consFreq[c]++;
            }
        }

       
        int maxfreq = 0;
        for(auto &it : vowelFreq){
            maxfreq = max(maxfreq, it.second);
        }

        
        int maxfreqcons = 0;
        for(auto &it : consFreq){
            maxfreqcons = max(maxfreqcons, it.second);
        }

        int ans = maxfreq + maxfreqcons;
        return ans;
    }
};
