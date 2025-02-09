class Solution {
public:
// void reverseArray(vector<int>& nums, int start, int end) {

//         while (start < end) {
//             int temp = nums[start];
//             nums[start] = nums[end];
//             nums[end] = temp;
//             start++, end--;
//         }
//     }
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         k = k % n;
//      vector<int> temp;
//      for(int i=0;i<k;i++){
//         temp.push_back(nums[i]);
//      }
//       for(int i=k; i < n; i++) {
//             nums[i-k] = nums[i];
//         }
//         for(int i=0; i < k; i++) {
//             nums[n-k+i] = temp[i];
//         }

//     }
// };
void rotate(vector<int>&nums,int k){
int n=nums.size();
k%=n;
reverse(nums.begin(),nums.end());
reverse(nums.begin(),nums.begin()+k);
reverse(nums.begin()+k,nums.end());
}
};