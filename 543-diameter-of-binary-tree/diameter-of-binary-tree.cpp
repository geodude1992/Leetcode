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
    /*
     * Calculate longest path passing through that node
     * Sum of the heights of its left and right subtrees
     * T: O(n) S:O(n) recursive calls
     */
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

    // Helper function to calculate the diameter recursively
    int dfs(TreeNode* current, int& result){
        if(current == nullptr){
            return 0;
        }
        int left = dfs(current->left, result);
        int right = dfs(current->right, result);

        result = max(result, left + right);

        // return max height of each subtree plus current node(1)
        return max(left, right) + 1;
    }     
};