class Solution {
public:
    // DP T:O(m*n) S:O(n)
    // 1) T[i-1][j-1] if str[i] == patt[j] || patt[j] == '?' Look at value at top-left diagonally from our position on table
    // 2) T[i][j] = T[i][j-1] || T[i-1][j] if patt[j] == '*' Look at value at top OR left from our position on table, take true if any
    // 3) False
    bool isMatch(string s, string p) {
        //vector<char> str(s.begin(), s.end());
        //vector<char> pat(p.begin(), p.end());

        // Set matrix with string length+1 Rows and a vector of Pattern length+1 Columns with cols set to false
        vector<vector<bool>> mat(s.size() + 1, vector(p.size() + 1, false));
        // Base Cases:
        // 1. When both the string and the pattern are empty. Always match. dp[0][0] = true;
        mat[0][0] = true;

        for(int j = 0; j < p.size() && p[j] == '*'; ++j){
            mat[0][j+1] = true;
        }

        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(p[j-1] == '?' || s[i-1] == p[j-1]){
                    mat[i][j] = mat[i-1][j-1];
                }else if(p[j-1] == '*'){
                    mat[i][j] = mat[i-1][j] || mat[i][j-1];
                }
            }
        }
        return mat[s.size()][p.size()];
    }
};