class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // m * n
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        // loop through the matrix
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                // ignore 0's
                if(grid[row][col] == 1){
                    // ADD 4
                    count+=4;
                    // first if neighboring cell is WITHIN bounds AND is land '1' SUBTRACT 1 from count
                    if(col+1 < n && grid[row][col+1] == 1){   // RIGHT
                        count--;
                    }
                    if(row+1 < m && grid[row+1][col] == 1) {   // DOWN
                        count--;
                    }
                    if(col-1 >= 0 && grid[row][col-1] == 1){ // LEFT
                        count--;
                    }
                    if(row-1 >= 0 && grid[row-1][col] == 1){ // UP
                        count--;
                    }
                }
            }
        }
        return count;
    }
};