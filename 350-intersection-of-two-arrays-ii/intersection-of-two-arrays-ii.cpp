class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1,map2;
        for(auto ele : nums1) map1[ele]++;
        for(auto ele : nums2) map2[ele]++;
        vector<int> result;
        for(auto it : map1) {
            if(map2.count(it.first)==1) {
                int n=min(map1[it.first],map2[it.first]);
                while(n>0) {
                    result.push_back(it.first);
                    n--;
                }
            }
        }
        return result;
    }
};