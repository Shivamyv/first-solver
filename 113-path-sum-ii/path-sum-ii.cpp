/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
     vector<vector<int>>ans;
     vector<int>curpath;
     int cursum=0;
     void solve(TreeNode* root,int targetSum){
        if(root==nullptr) return;
        cursum+=root->val;
        curpath.push_back(root->val);
        if((cursum==targetSum) && (root->left==nullptr ) && (root->right==nullptr))
         ans.push_back(curpath);

         solve(root->left,targetSum);
         solve(root->right,targetSum);
       cursum-=root->val;
       curpath.pop_back();
     }
       vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return ans;
       


     }
      
};