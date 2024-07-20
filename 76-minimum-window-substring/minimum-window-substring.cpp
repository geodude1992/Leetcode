class Solution {
public:
    /**
    Complexity
        Time complexity: O(n), where n is the length of string s.
        Space complexity: O(1), as the map array has a constant size (128).
    */
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length() < t.length()){
            return "";
        }

        vector<int> map(128, 0);
        int count = t.length();
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

        // Iterate through each character in string t and update the character frequency in the map
        for(char c : t){
            map[c]++;
        }
        
        while(end < s.length()){
            // increment end and decrement the freq in map for each character encountered until all characters from t are present in the window
            if(map[s[end++]]-- > 0){
                count--;
            }
            while(count == 0){  // characters from t are present in the window
                // When all characters from t are present, update minLen and startIndex based on the current window size and starting index
                if(end - start < minLen){
                    startIndex = start;
                    minLen = end - start;
                }
                // Increment start and increase the frequency in map until the window no longer contains all characters from t
                if(map[s[start++]]++ == 0){
                    count++;
                }
            }
        }
        // After the iteration, the minimum window is found, and the result is a substring of s starting from startIndex with length minLen
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};