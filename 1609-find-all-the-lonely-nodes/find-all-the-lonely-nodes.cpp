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
    // DFS Solution
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        dfs(root, false, result);
        return result;
    }
    
    void dfs(TreeNode* root, bool isLonely, vector<int>& lonelyNodes){
        // Return from DFS if root is NULL
        if (root == nullptr) return;
        if(isLonely){
            lonelyNodes.push_back(root->val);
        }
        dfs(root->left, root->right == nullptr, lonelyNodes);
        dfs(root->right, root->left == nullptr, lonelyNodes);
    }
};