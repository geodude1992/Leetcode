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
    /* Recursive Solution - T: O(n)
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->right, root->left);
    }

    bool isMirror(TreeNode* r, TreeNode* l){
        if(r == nullptr || l == nullptr) return r == l;
        return (r->val == l->val && isMirror(r->right, l->left) && isMirror(r->left, l->right));
    }*/

    // BFS Iterative
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> bfsq;
        bfsq.push(root);
        bfsq.push(root);
        while(!bfsq.empty()){
            TreeNode* t1 = bfsq.front(); bfsq.pop();
            TreeNode* t2 = bfsq.front(); bfsq.pop();

            if(t1 == nullptr && t2 == nullptr) continue;
            if(t1 == nullptr || t2 == nullptr) return false;
            if(t1->val != t2->val) return false;
            bfsq.push(t1->left);
            bfsq.push(t2->right);
            bfsq.push(t1->right);
            bfsq.push(t2->left);
        }
        return true;
    }
};