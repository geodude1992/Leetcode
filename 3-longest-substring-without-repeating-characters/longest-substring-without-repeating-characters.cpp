/*
// Set Solution
int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        unordered_set<char> charSet;
        int left = 0;

        for(int right = 0; right < n; ++right){
            if(charSet.count(s[right]) == 0){
                charSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1); // +1 since we start from 0th index
            } else {
                while (charSet.count(s[right])){
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }
        return maxLen;
    }
*/
class Solution {
public:
    // Unordered Map Solution
    int lengthOfLongestSubstring(string s) {
        // improve solution by using a map instead of a set
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> charMap; // store char as keys and indices as val
        int left = 0;

        for(int right = 0; right < n; ++right){
            // If the current character is not in the map or its index is less than left, it means it is a new unique character.
            if(charMap.count(s[right]) == 0 || charMap[s[right]] < left){
                charMap[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } else {
                // If the character is repeating within the current substring, we move the left pointer to the next position after the last occurrence of the character.
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }
        return maxLength;

    }
};