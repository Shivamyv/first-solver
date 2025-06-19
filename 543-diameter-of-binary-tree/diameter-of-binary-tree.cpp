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
    private: 
     int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
     if(root==nullptr) return 0;
     
     int leftheight=height(root->right);
     int rightheight=height(root->left);

    int diameter=leftheight+rightheight;
   int leftdiameter=diameterOfBinaryTree(root->left);
   int rightdiameter=diameterOfBinaryTree(root->right);
    return max(diameter,max(leftdiameter,rightdiameter));

    }
};