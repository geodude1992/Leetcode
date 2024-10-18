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
/*  The simplest strategy here is to use recursion.
Check if p and q nodes are not None, and their values are equal.
If all checks are OK, do the same for the child nodes
recursively.*/
    // Recursive Solution
    // T: O(n) n # of nodes 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};