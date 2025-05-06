/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // DFS Solution
    int maxDepth(Node* root) {
        if(!root) return 0;
        int mDepth = 0;
        for(auto child : root->children){
            mDepth = max(mDepth, maxDepth(child));
        }
        return 1 + mDepth;
    }

    /* BFS Solution
    int maxDepth(Node* root) {
        if(!root) return 0;
        int mDepth = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            mDepth++;
            int depthNodes = q.size();  // Save depth level size
            for(int i = 0; i < depthNodes; ++i){    // Traverse depth level size
                auto node = q.front(); q.pop();     // get a node
                for(auto child : node->children) {  // Traverse node's vector of children nodes
                    if(child) q.push(child);        
                }
            }
        }
        return mDepth;
    }*/
};