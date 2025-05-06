class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int icolor = image[sr][sc];     // Save Original color of starting point
        if(icolor != color) {           // if Og color is not new painted color run DFS
            dfs(image, sr, sc, icolor, color);
        }
        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int icolor, int color){
        // Check if we are within boundaries and the current pixel has not been painted and is original color
        if(row >= 0 && row < image.size() && col >= 0 && col < image[0].size() && image[row][col] != color && image[row][col] == icolor){
            image[row][col] = color;    // Paint current pixel
            dfs(image, row-1, col, icolor, color);
            dfs(image, row+1, col, icolor, color);
            dfs(image, row, col+1, icolor, color);
            dfs(image, row, col-1, icolor, color);
        }
    }
};