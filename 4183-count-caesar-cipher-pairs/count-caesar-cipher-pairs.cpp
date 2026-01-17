class Solution {
    using ll=long long;
public:
    long long countPairs(vector<string>& words) {
        map<string,int>mp;
        for(auto ch:words){
            int rot=ch[0]-'a';
            for(auto &c:ch){
                c='a'+((((c-'a')-rot)+26)%26);


            }
            mp[ch]++;
        }

        ll ans=0;
        for(auto&[x,y]:mp){
            ans+=((ll)y*(y-1))/2;
        }
       return ans;
    }
};