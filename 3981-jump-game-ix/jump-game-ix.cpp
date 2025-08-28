class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
       int n=nums.size();
       vector<int> mxpre(n);
        mxpre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            mxpre[i] = max(mxpre[i - 1], nums[i]);
        }
        
      
        vector<int> mnsuf(n);
        mnsuf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mnsuf[i] = min(mnsuf[i + 1], nums[i]);
        }
        
       
        vector<int> ans(n);
        int sgst = 0;  
        
        for (int i = 0; i < n - 1; i++) {
            if (mxpre[i] <= mnsuf[i + 1]) {  
                for (int j = sgst; j <= i; j++) {
                    ans[j] = mxpre[i];
                }
                sgst = i + 1;
            }
        }
        for (int j = sgst; j < n; j++) {
        
            ans[j] = mxpre[n - 1];
        }
        
        return ans;
        
    }
};