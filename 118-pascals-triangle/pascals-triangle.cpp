class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        
        for(int i = 0; i < numRows; i++){
            result[i].resize(i+1);

            // Each list starts with a 1
            result[i][0] = 1;

            // Middle
            for(int j = 1; j < i; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }

            // Each list ends with a 1
            result[i][i] = 1;
        }
        return result;
    }
};