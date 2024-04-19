class Solution {
    func dfs(_ grid: inout [[Character]], _ i: Int, _ j: Int) {
        // checks if the current cell (i, j) is within the bounds of the grid and is an unvisited land cell (char '1').
        // If any of these conditions are not met, the function immediately returns, 
        // preventing further execution of the DFS algorithm for that cell. 
        if i < 0 || i >= grid.count || j < 0 || j >= grid[0].count { return }
        if grid[i][j] != "1" { return }
        grid[i][j] = "0" // mark as visited
        
        // explore adjacent cells
        dfs(&grid, i+1, j) // down
        dfs(&grid, i-1, j) // up
        dfs(&grid, i, j+1) // right
        dfs(&grid, i, j-1) // left
    }

    func numIslands(_ grid: [[Character]]) -> Int {
        var grid = grid
        var islands = 0

        for row in 0..<grid.count {
            for col in 0..<grid[0].count {
                if grid[row][col] == "1" {
                    islands += 1
                    dfs(&grid, row, col)
                }
            }
        }
    
    return islands
    }
}