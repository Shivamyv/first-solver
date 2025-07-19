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
    bool dfs(TreeNode* root, int targetSum, int sum){
        if(root == NULL) return false;

        sum += root->val;

        // If we're at a leaf node, check if the path sum is equal to targetSum
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) return true;
        }

        // Otherwise, check left and right subtrees
        return dfs(root->left, targetSum, sum) || dfs(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;

        return dfs(root, targetSum, 0); // Initial sum is 0
    }
};