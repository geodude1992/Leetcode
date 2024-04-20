class Solution {
    func dfs(_ grid: inout [[Int]], _ i: Int, _ j: Int, _ start: Int, _ color: Int){
        var m = grid.count
        var n = grid[0].count
        // check if oob or cell is color or cell is start
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == color || grid[i][j] != start) { return }
        grid[i][j] = color
        dfs(&grid, i, j+1, start, color)
        dfs(&grid, i+1, j, start, color)
        dfs(&grid, i, j-1, start, color)
        dfs(&grid, i-1, j, start, color)
        return
    }

    func floodFill(_ image: [[Int]], _ sr: Int, _ sc: Int, _ color: Int) -> [[Int]] {
        var image = image
        dfs(&image, sr, sc, image[sr][sc], color)
        return image
    }
}