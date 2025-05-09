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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};    // Edge Case: Empty Tree

        vector<int> values;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qSize = q.size();
            int maxVal = INT_MIN;  // Constraint: -2^31 <= Node.val <= 2^31 - 1
            for(int i = 0; i < qSize; ++i){ 
                auto node = q.front(); q.pop();
                maxVal = max(node->val, maxVal);            
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            values.push_back(maxVal);
        }
        return values;
    }
};