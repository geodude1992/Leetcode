class Solution {
public:
    /* Union Find Solution - find the earliest time when all individuals are connected, directly/indirectly
        friendships are symmetric and transitive meaning efficiently solved by using 
        Union-Find (Disjoint Set Union)
    */
    // T: O(nlogn) - sorting logn - iterate n
    // S: O(n) - Group Array and Rank Array for optimization (not used)
    int find(int log, vector<int> &parent){
        // Retrieve the leader of an individuals group, apply path compression for efficiency
        if(parent[log] == log) return log;
        return find(parent[log], parent);
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        // First sort logs by timestamp
        sort(logs.begin(), logs.end());
        // Groups array to keep track of the leader of each persons group
        vector<int> groups(n);
        for(int i = 0; i < n; i++){
            groups[i] = i;
        }
        //vector<int> rank(n, 0);
        //int count = 0, ans = INT_MIN;

        // For each log entry, use Union join to merge groups if the 2 individuals belong to different groups
        for(auto &log : logs){
            int group1 = find(log[1], groups);
            int group2 = find(log[2], groups);
            if(group1 != group2){
                // Decrease a counter every time a successful union operation occurs. The counter is initally n
                n--;
                // Check for a single group, once the counter is 1, all individuals are interconnected and return current log entry
                if(n == 1) return log[0];
                groups[group1] = group2;
            }
        }
        return -1;  // dummy return value
    }
};