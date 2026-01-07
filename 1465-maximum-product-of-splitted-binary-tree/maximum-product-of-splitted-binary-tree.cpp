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
long long totalsum=0;
long long maxprod=0;
static const int mod=1e9+7;
   long long maxpathsum(TreeNode*root){
         if(root==nullptr) return 0;
         return root->val+maxpathsum(root->left)+maxpathsum(root->right);
   }
    long long dfs(TreeNode* root){
        if(root==nullptr) return 0;
        long long lsum=dfs(root->left);
        long long rsum=dfs(root->right);
        long long subtreesum=root->val+lsum+rsum;
        long long prod=subtreesum*(totalsum-subtreesum);
        maxprod=max(maxprod,prod);
        return subtreesum;
    }


    int maxProduct(TreeNode* root) {
      totalsum=maxpathsum(root);
      dfs(root);
      return maxprod % mod;
       
    }
};