class Solution {
public:
    // Map Characters
    bool isIsomorphic(string s, string t) {
        // Map unmapped characters, skip mapped characters, return false for mapped non-isomorphic characters
        // T: O(s + t)
        // S: O(n)
        unordered_map<char, char> mapStoT, mapTtoS;
        for(int i = 0; i < s.length(); ++i){
            if(mapStoT[s[i]] && mapStoT[s[i]] != t[i]) return false;
            if(mapTtoS[t[i]] && mapTtoS[t[i]] != s[i]) return false;
            mapStoT[s[i]] = t[i];
            mapTtoS[t[i]] = s[i];
        }
        return true;
    }
};