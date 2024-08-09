class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /*vector<int> r;
        for(int i = 0; i <= rowIndex; i++){
            r.assign(i+1, 1);
            for(int j = 1; j < i; j++){
                r[j] = r[j] + r[j-1];
            }
        }
        return r;*/
        vector<vector<int>> r(rowIndex+1);
        
        for(int i = 0; i <= rowIndex; i++){
            r[i].assign(i+1, 1);
            // Middle
            for(int j = 1; j < i; j++){
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }
        return r.back();
    }
};