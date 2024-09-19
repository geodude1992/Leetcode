#include <numeric> // gcd function
class Solution {
public:
    // T: O(min(m, n) * (m + n))
    // S: O(min(m, n))
    // k is the ratio of length of a string and base length
    bool valid(string str1, string str2, int k){
        int lenstr1 = str1.length(), lenstr2 = str2.length();
        if(lenstr1 % k > 0 || lenstr2 % k > 0) return false;
        else{
            // Copy k characters of str1 (starting from index 0)
            string base = str1.substr(0, k);
            int n1 = lenstr1 / k, n2 = lenstr2 / k;
            return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
        }
    }

    string joinWords(string str, int k){
        string answer = "";
        for(int i = 0; i < k; i++){
            answer += str;
        }
        return answer;
    }

    string gcdOfStrings(string str1, string str2) {
        int lenstr1 = str1.length(), lenstr2 = str2.length();
        for(int i = min(lenstr1, lenstr2); i >= 1; i--){
            if(valid(str1, str2, i)){
                return str1.substr(0, i);
            }
        }
        return "";
    }
};