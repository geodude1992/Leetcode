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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(node->left) {
                q.push(node->left);
                auto leaf = node->left;
                if(!leaf->left && !leaf->right) sum += node->left->val;
            }
            if(node->right) q.push(node->right);
        }
        return sum;
    }
};