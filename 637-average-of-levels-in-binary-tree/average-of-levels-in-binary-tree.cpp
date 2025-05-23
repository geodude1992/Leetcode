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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avgs;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvlsize = q.size();
            double lvlsum = 0;
            for(int i = 0; i < lvlsize; ++i){
                auto node = q.front(); q.pop();
                lvlsum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            avgs.push_back(lvlsum/lvlsize);
        }
        return avgs;
    }
};