class Solution {
public:
    // Map Characters
    bool isIsomorphic(string s, string t) {
        // Map unmapped characters, skip mapped characters, return false for mapped non-isomorphic characters
        // T: O(s + t)
        // S: O(n)
        unordered_map<char, char> umap, map2;
        for(int i = 0; i < s.length(); i++){
            if(umap[s[i]] && umap[s[i]] != t[i]) return false;
            if(map2[t[i]] && map2[t[i]] != s[i]) return false;
            umap[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        return true;
    }
};