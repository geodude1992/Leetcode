class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int count = 1;
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        
        while(left <= right && top <= bottom){
            // Traverse right while in top row
            for(int i = left; i <= right; i++){
                matrix[top][i] = count++;
            }
            top++;

            // Traverse down while in right column
            for(int i = top; i <= bottom; i++){
                matrix[i][right] = count++;
            }
            right--;
            
            if(left < right && top < bottom){
                // Traverse left while in bottom row
                for(int i = right; i >= left; i--){
                    matrix[bottom][i] = count++;
                }
                bottom--;

                // Traverse up while on the left column
                for(int i = bottom; i >= top; i--){
                    matrix[i][left] = count++;
                }
                left++;
            }
        }
        return matrix;
    }
};