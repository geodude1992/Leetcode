class Solution {
public:
    /* Recursive Brute Force Solution TLE - to get to (m, n) from (0, 0) the total unique paths is (m, n-1) and (m-1, n)
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }*/

    // DP Solution 
    // T: O(n*m)
    // S: O(n*m)
    int uniquePaths(int m, int n) {
        // Initialize matrix filled with 1's
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Iterate array number of paths are equal to 1 for first row and first column
        for(int col = 1; col < m; ++col){
            for(int row = 1; row < n; ++row){
                // Iterate over all 'inner' cells
                dp[col][row] = dp[col - 1][row] + dp[col][row - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};