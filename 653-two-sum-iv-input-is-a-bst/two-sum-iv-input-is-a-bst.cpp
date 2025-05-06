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
    bool findTarget(TreeNode* root, int k) {
        vector<int> trav;
        inorder(root, trav);
        int l = 0, r = trav.size()-1;
        while(l < r){
            int sum = trav[l] + trav[r];
            if(sum == k) return true;
            if(sum < k) l++;    // Increase calcalated sum
            else r--;           // Decrease calculated sum
        }
        return false;
    }

    // INORDER Traversal Left=>Root=>Right
    void inorder(TreeNode* node, vector<int>& v){
        if(!node) return;
        inorder(node->left, v); // Visited Left
        v.push_back(node->val);
        inorder(node->right, v);
    }
};