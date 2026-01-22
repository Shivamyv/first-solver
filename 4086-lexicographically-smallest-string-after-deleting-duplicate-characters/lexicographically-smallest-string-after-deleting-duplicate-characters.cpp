class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n = s.size();
        vector<int> first(26,n), last(26,-1);
        array<bool,26> present{};
        for(int i = 0; i < n; i++) {
            if(first[s[i] - 'a'] == n) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        vector<array<int,26>> nex(n + 1);
        for(int i = 0; i < 26; i++) {
            nex.back()[i] = n;
        }

        for(int i = n-1; i >= 0; i--) {
            nex[i] = nex[i + 1];
            nex[i][s[i]-'a'] = i;
        }

        string ans;

        for(int i = 0; i < n; i++) {

            //preliminary check: can we delete every letter after i including i?
            bool flag1 = true;
            for(int j = 0; j < 26; j++) {
                //either there should be no occurences of j >= i, or there should be an occurence of j before i
                if(last[j] < i || present[j]) /*badhiya*/;
                else flag1 = false;
            }
            if(flag1) {
                return ans;
            }
            flag1 = true;
            for(int j = 0; j < s[i] - 'a'; j++) {
                //can j come here?
                int ne = nex[i][j];
                // if(j == s[i] - 'a') continue;
                if(ne == n) continue;
                bool flag = true;
                for(int k = 0; k < 26; k++) {
                    //check if we can delete all instances of k
                    //in range [i,ne)
                    //either present[k] OR
                    //there is an instance of k >= ne OR
                    //there is no instance of k in the range
                    if(present[k] || last[k] >= ne || nex[i][k] >= ne) {
                        //then we can delete all instances of k
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ans += 'a' + j;
                    present[j] = true;
                    flag1 = false;
                    i = ne;
                    break;
                }
            }
            if(flag1) {
                ans += s[i];
                present[s[i] - 'a'] = true;
            }
        }

        return ans;
    }
};