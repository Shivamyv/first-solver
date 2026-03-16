class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>cnt1,cnt2;
    for(int x:nums1) cnt1[x]++;
    for(int x:nums2) cnt2[x]++;
    unordered_set<int>st;
    for(auto &p:cnt1) st.insert(p.first);
    for(auto &p:cnt2) st.insert(p.first);
    long long diff=0;
    for(int v:st){
        int c1=cnt1[v];
        int c2=cnt2[v];

        if((c1+c2)%2!=0) return -1;
        diff+=abs(c1-c2);
    }


  return diff/4;

    }
};