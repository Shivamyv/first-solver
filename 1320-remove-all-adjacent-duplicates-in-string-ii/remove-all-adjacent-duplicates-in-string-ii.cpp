class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char ch:s){
            if(!st.empty()&& st.top().first==ch){
                st.top().second++;

                if(st.top().second==k){
                    st.pop();
                }
            }
                else{
                    st.push({ch,1});
                }
        }
        string ans="";
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            int leftchar=it.first;
            int count=it.second;
            ans+=string(count,leftchar);


        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};