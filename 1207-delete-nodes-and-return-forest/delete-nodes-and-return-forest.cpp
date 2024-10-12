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
    /** Optimal lookup time for deletion, to_delete is converted into a set, set allow O(1) compared to O(n) array */

    /*  Recursion Solution (Post Order Traversal - childs than parent) - Process each node's child nodes
        T: O()
        S: O()
    */
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Convert to_delete array into a set for efficient lookups
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        // Create result array forest
        vector<TreeNode*> forest;

        // Recursive Postorder traversal
        root = processNode(root, toDeleteSet, forest);

        // if the root is not deleted, add it to the forest array
        if(root){
            forest.push_back(root);
        }
        return forest;
    }

    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest){
        if(!node){
            return nullptr;
        }
        // Recursive Postorder traversal to ensure we process all child nodes before
        node->left = processNode(node->left, toDeleteSet, forest);
        node->right = processNode(node->right, toDeleteSet, forest);

        // Check if current node needs deletion by checking if value exist in to_delete set
        if(toDeleteSet.find(node->val) != toDeleteSet.end()){
            // Check if node has children, left/right not null, added them to forest array
            if(node->left){
                forest.push_back(node->left);
            }
            if(node->right){
                forest.push_back(node->right);
            }
            // Delete current node and return null
            delete node;
            return nullptr;
        }
        // if node does not need to be deleted return node
        return node;
    }
};