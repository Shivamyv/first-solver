class Solution {
public:
  void f(unordered_set<string>&st,string &temp,int n){
    if(temp.size()==n) {
        st.insert(temp);
        return;
    }
     temp.push_back('1');
     f(st,temp,n);
     temp.pop_back();
     temp.push_back('0');
     f(st,temp,n);
     temp.pop_back();



  }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>st;
        string temp="";
        f(st,temp,n);
        for(auto s:nums){
            if(st.find(s)!=st.end()) st.erase(s);

        }
        return *st.begin();
    }
};