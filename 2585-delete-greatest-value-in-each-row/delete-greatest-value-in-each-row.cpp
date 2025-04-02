class Solution {
public:
    // Sort with Max Heap Solution
    // T: O(m log m) | m rows
    // S: O(n) pq
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sumOfMaxs = 0;

        // 1. Sort each row of the grid.
        for(auto &row : grid)
            sort(row.rbegin(), row.rend());
        
        // 2. for each column, use a priority queue to find the largest value in that column.
        for(int col = 0; col < grid[0].size(); ++col){
            priority_queue<int> pq;
            for(int row = 0; row < grid.size(); ++row){
                pq.push(grid[row][col]);
            }
            // 3. Add these largest values together to get the final answer.
            sumOfMaxs += pq.top();
        }

        return sumOfMaxs;
    }
};