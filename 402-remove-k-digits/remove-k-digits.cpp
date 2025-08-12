class Solution {
public:
    string removeKdigits(string num, int k) {
     int n=num.size();
     
     string ans="";
     stack<int>st;
     for(int i=0;i<n;i++){
        char currelement=num[i];
        while(!st.empty() && k > 0 && st.top()>currelement ){
            st.pop();
            k--;
        }
        st.push(currelement);
     }
        while(!st.empty() && k>0 ){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "0";

     

   return ans;

    }
};