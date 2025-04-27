class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j){
        // boundary checking
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        // return if current position is of water=='0' or is already visited=='2'
        if(grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '0';

        // do DFS in all 4 directions
        DFS(grid, i+1, j);    // DOWN
        DFS(grid, i, j+1);    // RIGHT
        DFS(grid, i-1, j);    // UP
        DFS(grid, i, j-1);    // LEFT
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};