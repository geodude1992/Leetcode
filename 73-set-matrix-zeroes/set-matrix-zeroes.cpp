class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int leftCol = 1, rows = matrix.size()-1, cols = matrix[0].size()-1;
        
        // Use elements to set states in a top-down way
        for(int i = 0; i <= rows; i++){
            if(matrix[i][0] == 0) leftCol = 0;
            for(int j = 1; j <= cols; j++){
                if(matrix[i][j] == 0) 
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        // Use states to set matrix elements in a bottom-up way
        for(int i = rows; i >= 0; i--){
            for(int j = cols; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(leftCol == 0) matrix[i][0] = 0;
        }
    }
};