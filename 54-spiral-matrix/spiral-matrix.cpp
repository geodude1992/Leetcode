class Solution {
public:
    // Set Boundaries move inward
    // T: O(M * N) - Visited each element once
    // S: O(1) - No extra memory is used. Resulting vector is ignored in complexity
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        // Initialize 2 Pointers top and bottom (ROWS)
        int top = 0, bottom = matrix.size() - 1;
        // Initialize 2 Pointers left and right (COLUMNS)
        int left = 0, right = matrix[0].size() - 1;

        while(top <= bottom && left <= right){
            // Traverse right when on top row
            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            // Increment to the next row
            top++;

            // Traverse down when on right column
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            // Traverse left when on bottom row
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse up when on the left column
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};