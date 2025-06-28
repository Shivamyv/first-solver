class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        vector<int> ans;

        
        sort(temp.begin(), temp.end(), greater<int>());

       
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            freq[temp[i]]++;
        }

     
        for (int num : nums) {
            if (freq[num] > 0) {
                ans.push_back(num);
                freq[num]--;
            }
            if (ans.size() == k) break;
        }

        return ans;
    }
};
