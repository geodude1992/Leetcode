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
    int minDiffInBST(TreeNode* root) {
        vector<int> sorty;
        inorder(root, sorty);

        int minDiff = INT_MAX;
        for(int i = 1; i < sorty.size(); ++i){
            minDiff = min(sorty[i] - sorty[i-1], minDiff);
        }
        return minDiff;
    }

    void inorder(TreeNode* node, vector<int>& v){
        if(!node) return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
};