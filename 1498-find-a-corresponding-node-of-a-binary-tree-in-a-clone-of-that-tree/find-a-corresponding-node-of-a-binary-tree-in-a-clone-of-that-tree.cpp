/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(original);
        q.push(cloned);
        TreeNode* cNode;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            cNode = q.front(); q.pop();
            if(cNode->val == target->val) break;
            if(node->left){
                q.push(node->left);
                q.push(cNode->left);
            }
            if(node->right){
                q.push(node->right);
                q.push(cNode->right);
            }
        }
        return cNode;
    }
};