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
    // Recursive DFS T: O(n) S: O(H)
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

    // Recursive BF
    /*
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int depth = 0;
        // Use queue for BFS
        std::deque<TreeNode*> deq(root);

        while(dep!=nullptr){

        }
    }*/

    // Iterative BFS
    /*int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
    }*/
};