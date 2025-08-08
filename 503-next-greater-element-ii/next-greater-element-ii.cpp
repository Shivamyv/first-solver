class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n=nums.size();
     vector<int>ans(n,-1);
     stack<int>st;
     for(int i=2*n-1;i>=0;i--){
        int ind= i % n;
        
        int currelement=nums[ind];

     
     while(!st.empty() && st.top()<=currelement){
        st.pop();
     }

    
    if (i < n && !st.empty()) {
                ans[ind] = st.top();
            }
     st.push(currelement);

    }
     return ans;
     
        
    }
};