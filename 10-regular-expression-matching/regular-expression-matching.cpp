class Solution {
public:
    /* Recursion Solution TLE - kleene star must come after the first char 
    // T: O((S + P) * 2^(S + P/2)) - 
    // S: O(S^2 + P^2) - each call to isMatch will create strings possible duplicates 
    bool isMatch(string s, string pattern) {
        if(pattern.empty()) return s.empty();
        bool first_match = (s != "" && (pattern.at(0) == s.at(0) || pattern.at(0) == '.'));

        if(pattern.length() >= 2 && pattern.at(1) == '*'){
            return (isMatch(s, pattern.substr(2)) || (first_match && isMatch(s.substr(1), pattern)));
        }

        // If no Kleen Stars simply check string left to right if each character matches the pattern
        return (first_match && isMatch(s.substr(1), pattern.substr(1)));
    }*/

    // DP Solution - Bottom Up Approach
    // T: O(s * p) 
    // S: O(s * p)
    bool isMatch(string s, string pattern) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(pattern.length() + 1, 0));
        dp[s.length()][pattern.length()] = 1;

        // Iterate through string s
        for(int i = s.length(); i >= 0; i--){
            // Iterate through pattern
            for(int j = pattern.length() - 1; j >= 0; j--){
                bool first_match = (i < s.length() && (pattern[j] == s[i] || pattern[j] == '.'));

                if(j + 1 < pattern.length() && pattern[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                }else{
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};