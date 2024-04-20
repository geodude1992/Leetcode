class Solution {
public:
    void dfs(vector<vector<int>>& grid , vector<vector<bool>>& vis , int i , int j ,int val, int color){
        int m = grid.size();
        int n = grid[0].size();

        // base case retrun if out of bounds or cell already visited or cell not a connected component
        if( i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] != val)
            return;
        
        vis[i][j] = true;
        
        // check if cell on the border of the grid or not
        if(i == 0 || j == 0 || i >= m-1 || j >= n-1)
            grid[i][j] = color;

        // conditon to check if adjacent cell is within grid and not visited and not cc
        if( (j + 1 <= n-1 && grid[i][j+1] != val && !vis[i][j+1]) || 
            (i + 1 <= m-1 && grid[i+1][j] != val && !vis[i+1][j]) || 
            (j - 1 >= 0 && grid[i][j-1] != val && !vis[i][j-1]) ||
            (i - 1 >= 0 && grid[i-1][j] != val && !vis[i-1][j]) )
            grid[i][j] = color;

        // DFS
        dfs(grid, vis, i, j+1, val, color); // Right
        dfs(grid, vis, i+1, j, val, color); // down
        dfs(grid, vis, i, j-1, val, color); // left
        dfs(grid, vis, i-1, j, val, color); // up
        
        return;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        // What question has asked?
        // in the connectred component mark all the values to the colored one which are on the border of the sqaure 
        // or who has adjacently atleast one square which is not the part of connected component.
        // color border: borders are the bounds of the grid AND adjacent to a square not in component
        // color all values with value = grid[row][vol] 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(grid, visited, row, col, grid[row][col], color);
        return grid;
    }
};