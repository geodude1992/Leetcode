class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int icolor = image[sr][sc];
        if(icolor != color) {
            dfs(image, sr, sc, icolor, color);
        }
        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int icolor, int color){
        if(row >= 0 && row < image.size() && col >= 0 && col < image[0].size() && image[row][col] != color && image[row][col] == icolor){
            image[row][col] = color;
            dfs(image, row-1, col, icolor, color);
            dfs(image, row+1, col, icolor, color);
            dfs(image, row, col+1, icolor, color);
            dfs(image, row, col-1, icolor, color);
        }
    }
};