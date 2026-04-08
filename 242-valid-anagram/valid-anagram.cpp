class Solution {
public:
    bool isAnagram(string s, string t) {
       if (s.size() != t.size()) return false;
        unordered_map<char,int>mpp;
        
        for(char c:s){
            mpp[c]++;
        }
        for(char ch:t){
            mpp[ch]--;
            if(mpp[ch]<0) return false;
        }
        return true;
    }
};