class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        unordered_map<char,int> mp;

        for(auto i:p){
            mp[i]++;
        }

        for(int i=0;i<=n-m;i++){
            string sub = s.substr(i,m);

            unordered_map<char,int> mp1;

            for(auto i:sub){
                mp1[i]++;
            }

            if(mp1 == mp){
                ans.push_back(i);
            }
        }
        return ans;
    }
};