class Solution {
public:
    /* Brute force Solution TLE
    // T: O((m*n)^2)
    // S: O(1) - no extra memory used
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        // Largest square found
        int largestSq = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1'){
                    // Current Sq
                    int currentSq = 1;
                    bool flag = true;
                    // Move diagonally(right and downwards)
                    while(currentSq + i < rows && currentSq + j < cols && flag){
                        for(int k = j; k <= currentSq + j; k++){
                            if(matrix[i + currentSq][k] == '0'){
                                flag = false;
                                break;
                            }
                        }for(int k = i; k <= currentSq + i; k++){
                            if(matrix[k][j + currentSq] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        if(flag) currentSq++;
                    }
                    if(largestSq < currentSq) largestSq = currentSq;
                }
            }
        }
        // Diagonal length is equal to the side length of the square return the area = largestSq^2
        return largestSq * largestSq;
    }*/

    // DP Solution
    // T: O(m * n) - Single pass
    // S: O(m * n) - Another matrix of same size is used for dp
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        // Use another matrix(dp) with 0's
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int largestSq = 0;
        
        // For convenience, we add an extra all zero row and column
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                if(matrix[i - 1][j - 1] == '1'){
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    largestSq = max(largestSq, dp[i][j]);
                }
            }
        }
        return largestSq * largestSq;
    }
};