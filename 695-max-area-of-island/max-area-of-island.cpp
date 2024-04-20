class Solution {
public:
    // Time complexity: O(m*n)
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        // check if we are in bounds
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return 0;

        // We don’t wanna use any extra space to keep track of visited elements, so after visiting any 1, we’ll make it 2.
        grid[i][j]=2;
        return (1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // go through the grid
        // dfs on each land and keep count
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    // result will be the max of current dfs call + previous result.
                    result = max(result, dfs(grid, i, j));
            }
        }
        // To make the array back to original, we’ll convert all 2 to 1.
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    grid[i][j] = 1;
            }
        }
        return result;
    }
};