class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        //priority_queue<int> pq;
        int sumOfMaxs = 0;

        // Sort
        for(auto &x : grid)
            sort(x.rbegin(), x.rend());
        
        for(int i = 0; i < grid[0].size(); i++){
            priority_queue<int> pq;
            for(int j = 0; j < grid.size(); j++){
                pq.push(grid[j][i]);
            }
            sumOfMaxs += pq.top();
        }

        return sumOfMaxs;
    }
};