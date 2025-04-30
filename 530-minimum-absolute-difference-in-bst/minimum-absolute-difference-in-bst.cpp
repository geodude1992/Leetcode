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
    TreeNode* prev = nullptr;
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        inorderTraversal(root, minDiff);
        return minDiff;
    }

    void inorderTraversal(TreeNode* node, int& m){
        if(node == nullptr) return;
        inorderTraversal(node->left, m);
        if(prev != nullptr) m = min(m, abs(prev->val - node->val));
        prev = node;
        inorderTraversal(node->right, m);
    }
};