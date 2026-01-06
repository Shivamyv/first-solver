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
    int maxLevelSum(TreeNode* root) {
       map <int, int> sum;
        queue<pair<TreeNode*, int> > Q;
        Q.push({root, 1});
        while(!Q.empty()){
            auto u = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            sum[depth] += u -> val;
            if(u -> left != NULL){
                Q.push({u -> left, depth + 1});
            }
            if(u -> right != NULL){
                Q.push({u -> right, depth + 1});
            }
        }
        int d = 1;
        for(auto [depth, s] : sum){
            if(s > sum[d]){
                d = depth;
            }
        }
        return d;

    }
};