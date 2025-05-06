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
    int findBottomLeftValue(TreeNode* root) {
        int lefty = 0;
        queue<TreeNode*> q;
        q.push(root);
        lefty = root->val;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(node->right){
                q.push(node->right);
                if(!node->left) lefty = node->right->val;
            }
            if(node->left){
                q.push(node->left);
                lefty = node->left->val;
            }
        }
        return lefty;
    }
};