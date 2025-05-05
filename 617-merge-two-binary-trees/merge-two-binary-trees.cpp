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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2){
            return root1 ? root1 : root2;
        }
        queue<TreeNode*> q;
        q.push(root1); q.push(root2);
        while(!q.empty()){
            TreeNode* node1 = q.front(); q.pop();
            TreeNode* node2 = q.front(); q.pop();
            node1->val = node1->val + node2->val;
            // One node has a missing left node
            if(!node1->left && node2->left){
                node1->left = node2->left;
            }else if(node1->left && node2->left){   // Both have a left node
                q.push(node1->left);
                q.push(node2->left);
            }
            // One node has a missing right node
            if(!node1->right && node2->right){
                node1->right = node2->right;
            }else if(node1->right && node2->right){ // Both have a right node
                q.push(node1->right);
                q.push(node2->right);
            }
        }
        return root1;
    }
};