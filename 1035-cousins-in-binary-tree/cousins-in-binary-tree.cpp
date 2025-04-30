#include <queue>
using namespace std;
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            bool foundx = false, foundy = false;
            for(int i = 0; i < n; ++i){
                TreeNode* temp = q.front();
                q.pop();

                // If values are found
                if(temp->val == x) foundx = true;
                if(temp->val == y) foundy = true;

                // Check if their parents are the same
                if(temp->left && temp->right){
                    if( (temp->left->val == x && temp->right->val == y) || 
                        (temp->left->val == y && temp->right->val == x))
                        return false;
                }
                // Push temp left and right child to queue
                if(temp->left != nullptr)
                    q.push(temp->left);
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
            // If both are found at the same level and not siblings, they are cousins
            if(foundx && foundy) return true;
        }
        return false;
    }
};