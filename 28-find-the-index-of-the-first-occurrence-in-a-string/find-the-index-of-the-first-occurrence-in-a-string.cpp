class Solution {
public:
    // T: O(n * m) | S: O(1)
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;
        // goes up to len(haystack) - len(Needle). 
        //This is done to ensure that there are enough characters left in the haystack for the needle to fit.
        for(int i = 0; i <= haystack.length() - needle.length(); i++){
            if(haystack.substr(i, needle.length()) == needle){
                return i;
            }
        }
        return -1;
    }
};