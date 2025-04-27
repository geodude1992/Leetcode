#include <unordered_set>

class Solution {
public:
    // DFS Solution
    int numDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        std::unordered_set<std::string> islands;

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j]){
                    std::string island;
                    dfs(grid, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
private:
    void dfs(std::vector<std::vector<int>>& grid, int i, int j, int r, int c, std::string& island){
        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c]){
            // Append a 0 to know where we backtracked so we dont get 
            grid[r][c] = 0;
            island += std::to_string(r - i) + std::to_string(c - j);
            dfs(grid, i, j, r-1, c, island); // UP
            dfs(grid, i, j, r+1, c, island);
            dfs(grid, i, j, r, c-1, island);
            dfs(grid, i, j, r, c+1, island);
        }
    }
};