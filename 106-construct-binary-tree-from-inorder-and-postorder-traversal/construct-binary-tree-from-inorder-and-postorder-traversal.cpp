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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
   unordered_map<int,int> mpp;
   for(int i=0;i<inorder.size();i++){
    mpp[inorder[i]]=i;
   }
   return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);

    }
TreeNode* buildTree(vector<int>& inorder,int instart,int inend, vector<int>& postorder, int poststart,int postend,unordered_map<int,int> &mpp) {
   if(instart>inend || poststart > postend){
    return nullptr;
   }
    

   TreeNode * root=new TreeNode(postorder[postend]);

   int inRoot=mpp[root->val];

   int leftsubtreesize=inRoot-instart;
   root->left=buildTree(inorder,instart,inRoot-1,postorder,poststart,poststart 
     +leftsubtreesize-1,mpp);
     root->right=buildTree(inorder,inRoot+1,inend,postorder,poststart
     +leftsubtreesize,postend-1,mpp);
     return root;

}

};