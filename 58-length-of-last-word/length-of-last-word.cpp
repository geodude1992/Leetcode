class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordlength = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s.at(i) != ' ') wordlength++;
            else if(s.at(i) == ' ' && wordlength > 0) break;
            else continue; 
        }
        return wordlength;
    }
};