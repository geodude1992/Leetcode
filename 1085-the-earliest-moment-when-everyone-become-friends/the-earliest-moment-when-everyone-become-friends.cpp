class Solution {
public:
    /* Union Find Solution - find the earliest time when all individuals are connected, directly/indirectly
        friendships are symmetric and transitive meaning efficiently solved by using 
        Union-Find (Disjoint Set Union)
    */
    // T: O(nlogn) - sorting logn - iterate n
    // S: O(n) - Group Array and Rank Array for optimization (not used)

    // Find function - find what group, person p belongs to
    int find(int p, vector<int> &parentGroup){
        // Retrieve the leader of an individuals group, apply path compression for efficiency
        if(parentGroup[p] != p) return find(parentGroup[p], parentGroup);    // We have not reach the root of the tree
        return p;
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        // First sort logs by timestamp
        sort(logs.begin(), logs.end());
        // Parent array to keep track of the leader of each persons group. Initally each person is a leader
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        //vector<int> rank(n, 0);
        //int count = 0, ans = INT_MIN;

        // For each log entry, use Union join to merge groups if the 2 individuals belong to different groups
        for(auto &log : logs){
            int group1 = find(log[1], parent);
            int group2 = find(log[2], parent);
            if(group1 != group2){
                // Decrease a counter every time a successful union operation occurs. The counter is initally n
                n--;
                // Check for a single group, once the counter is 1
                // all individuals are interconnected and return current log entry
                if(n == 1) return log[0];
                // Union Operation - connect two individuals by assigning same leader
                parent[group1] = group2;    // Union Function Par[find(y)] = find(x)
            }
        }
        return -1;  // dummy return value
    }
};