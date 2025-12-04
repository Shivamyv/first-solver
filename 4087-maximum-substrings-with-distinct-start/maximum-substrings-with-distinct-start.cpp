class Solution {
public:
    int maxDistinct(string s) {
        
        unordered_map<char,int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        return mpp.size();

    }
};