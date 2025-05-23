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
    // BFS Solution
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q; 
        q.push(root);   // Enqueue Root
        while(!q.empty()){
            auto node = q.front(); q.pop(); // Dequeue
            if(node->left) {
                q.push(node->left);
                auto leaf = node->left;     // left leaf node
                if(!leaf->left && !leaf->right) sum += leaf->val;
            }
            if(node->right) q.push(node->right);
        }
        return sum;
    }
};