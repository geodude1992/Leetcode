class Solution {
public:
    // Backtracking solution
    // T: O()
    // S: O()
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentSubstring;
        backtrack(0, s, currentSubstring, result);
        return result;
    }

    void backtrack(int idx, string& s, vector<string>& currStr, vector<vector<string>>& result){
        if(idx >= s.length()) result.push_back(currStr);

        for(int i = idx; i < s.length(); ++i){
            // Check if current string is palindrome
            if(isPalindrome(s, idx, i)){
                // Add current substring in the currentList starting at position idx with length i - idx + 1 (+1 for offset)
                currStr.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, currStr, result);
                // backtrack and remove the current substring from our array of strings
                currStr.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};