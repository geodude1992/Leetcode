class Solution {
public:
    // Hashmap Solution
    // T: O(n)
    // S: O(n)
    char findTheDifference(string s, string t) {
        // Map characters in s and increment count. Map t and decrement count
        unordered_map<char, int> mapS;

        // Traverse string t and increment count since t will have more characters than s
        for(int i = 0; i < t.size(); ++i){
            mapS[t[i]]++;
        }
        // Traverse string s and decrement count since s will have less characters than t
        for(int i = 0; i < s.size(); ++i){
            mapS[s[i]]--;
        }

        for(auto itr : mapS){
            if(itr.second == 1){
                return itr.first;
            }
        }
        // Return dummy
        return mapS[0];
    }
};