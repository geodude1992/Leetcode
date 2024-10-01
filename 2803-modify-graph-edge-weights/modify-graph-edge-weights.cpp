class Solution {
public:
    // Traditional Dijkstra's Algorithm
    // T: O(E * V^2)
    // S: O(V^2)
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int nodeCount, vector<vector<int>>& edges, int source, int destination, int target) {
        // Step 1: Compute the initial shortest distance from source to destination
        long long currentShortestDistance = runDijksta(edges, nodeCount, source, destination);

        // If the current shortest distance is less than the target, return an empty result
        if(currentShortestDistance < target) return {};
        bool matchesTarget = (currentShortestDistance == target);

        // Step 2: Iterate through each edge to adjust its weight if necessary
        for(vector<int>& edge : edges){
            // Skip edges that already have a postive weight
            if(edge[2] > 0) continue;

            // Set edge weight to a large value if current distance matches target else set to 1
            edge[2] = matchesTarget ? INF : 1;

            // Step 3: If current shortest distance does not match target
            if(!matchesTarget){
                // Compute the new shortest distance with the updated edge weight
                long long newDistance = runDijksta(edges, nodeCount, source, destination);

                // If the new distance is within the target range, update edge weight to match target
                if(newDistance <= target){
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }
        // Return modifies edges if the target distance is achieved, otherwise return an empty result
        return matchesTarget ? edges : vector<vector<int>>{};
    }

    long long runDijksta(const vector<vector<int>>& edges, int nodeCount, int sourceNode, int destinationNode){
        // Step 1: Initialize adjacency matrix with a large value (INF) to represent no direct connection between nodes.
        vector<vector<long long>> adjMatrix(nodeCount, vector<long long>(nodeCount, INF));
        // Initialize distance array from the source node to each node, initially set to INF.
        vector<long long> minDistance(nodeCount, INF);
        vector<bool> visited(nodeCount, false);

        // Set the distance to the source node as 0 since shortest path is itself
        minDistance[sourceNode] = 0;

        // Step 2: Fill the adjacency matrix with edge weights
        for(const vector<int>& edge : edges){
            if(edge[2] != -1){
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        // Step 3: Perform Dijkstra's algorithm
        for(int i = 0; i < nodeCount; i++){
            // Find the nearest unvisited node
            int nearestUnvisitedNode = -1;
            for(int j = 0; j < nodeCount; j++){
                // Find the nearest unvisited node with the smallest distance from the source.
                if(!visited[j] && 
                    (nearestUnvisitedNode == -1 || minDistance[j] < minDistance[nearestUnvisitedNode])) {
                        nearestUnvisitedNode = j;
                }
            }
            // Mark the nearest node as visited
            visited[nearestUnvisitedNode] = true;

            // Update the minimum distance for each adjacent node
            for(int v = 0; v < nodeCount; v++){
                minDistance[v] = min(minDistance[v], minDistance[nearestUnvisitedNode] + 
                    adjMatrix[nearestUnvisitedNode][v]);
            }
        }
        // Return the shortest distance to the destination node
        return minDistance[destinationNode];
    }
};

/*
class Solution {
public:
    // Traditional Dijkstra's Algorithm
    // T: O(E * (V + E)log V)
    // S: O(V + E)
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
    }
};
*/