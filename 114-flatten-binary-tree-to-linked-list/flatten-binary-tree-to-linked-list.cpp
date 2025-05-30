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
    // Morris Traversal
    // T: O(N)
    // S: O(1)
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* runner = curr->left;
                while(runner->right!=nullptr) {
                    runner = runner->right;
                }
                runner->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // move curr to the right when there are no left nodes
            curr = curr->right;
        }
    }
};