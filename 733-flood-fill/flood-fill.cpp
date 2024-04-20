class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int target, int color){
        int m = image.size();
        int n = image[0].size();
        // base case: return if we are out of bounds and cell already the color and is not the target
        if(r < 0 || c < 0 || r >= m || c >= n || image[r][c] == color || image[r][c] != target ) return;
        image[r][c] = color;

        dfs(image, r, c+1, target, color);
        dfs(image, r+1, c, target, color);
        dfs(image, r, c-1, target, color);
        dfs(image, r-1, c, target, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};