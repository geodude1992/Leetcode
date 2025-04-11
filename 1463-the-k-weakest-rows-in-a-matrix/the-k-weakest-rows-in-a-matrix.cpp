class Solution {
public:
    // Sort Solution - modifies input vector
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // list of k weakest 
        vector<int> result(k);
        // Declare n BEFORE modifying the rows since we are appending a extra column
        int n = mat[0].size();
        // append row index to the end of each row
        for(int i = 0; i < mat.size(); ++i){
            mat[i].push_back(i);
        }
        // Sort rows on the basis of the first element, if same then 2nd element, and so on
        sort(mat.begin(), mat.end());
        // 
        for(int i = 0; i < k; ++i){
            result[i] = mat[i][n];
        }
        return result;
    }
};