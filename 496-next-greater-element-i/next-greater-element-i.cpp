class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
     vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size();
       unordered_map<int,int>mpp;


       
        stack<int>st;
       for(int i=m-1;i>=0;i--){
        int curelement=nums2[i];
       
            while(!st.empty() && st.top()<=curelement)  {
              st.pop();
            }

           mpp[curelement]=st.empty() ? -1 : st.top();

            st.push(curelement);
       }
            vector<int>ans;
             for(int num:nums1){
                ans.push_back(mpp[num]);
             }
            
        
   return ans;

    }
};

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> nextGreater;
//         stack<int> st;

//         // Step 1: Traverse nums2 in reverse to find the next greater element
//         for (int i = nums2.size() - 1; i >= 0; --i) {
//             int num = nums2[i];

//             // Maintain decreasing stack: pop all elements <= current
//             while (!st.empty() && st.top() <= num) {
//                 st.pop();
//             }

//             // If stack is empty => no next greater element
//             nextGreater[num] = st.empty() ? -1 : st.top();

//             // Push current number onto the stack
//             st.push(num);
//         }

//         // Step 2: Build the answer for nums1 using the map
//         vector<int> ans;
//         for (int num : nums1) {
//             ans.push_back(nextGreater[num]);
//         }

//         return ans;
//     }
// };
