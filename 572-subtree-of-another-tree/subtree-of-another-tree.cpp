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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr || subRoot == nullptr){
            return root == NULL && subRoot == NULL;
        }
        // Check value of each node
        else if(root->val == subRoot->val){
            // recursive call
            return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
        }else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // check if the root is empty
        if(root == nullptr){
            return false;
        }// Check if tree 1 and tree 2 are the same
        else if(isSameTree(root, subRoot)){   
            return true;
        }// Check if child nodes of tree 1 match tree 2
        else{
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
};