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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
     vector<vector<int>> ans; 
        if (root == nullptr) {
            // If the tree is empty, return an empty vector
            return ans; 
        }
        
        // Create a queue to store nodes for level-order traversal
        queue<TreeNode*> q; 
        // Push the root node to the queue
        q.push(root); 

        while (!q.empty()) {
            // Get the size of the current level
            int size = q.size(); 
            // Create a vector to store nodes at the current level
            vector<int> level; 

            for (int i = 0; i < size; i++) {
               
                TreeNode* node = q.front(); 
               
                q.pop(); 
               
                level.push_back(node->val); 

                
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            ans.push_back(level); 
        }
       
        return ans; 


    }
};