#include <numeric> // gcd function
class Solution {
public:
    /* T: O(min(m, n) * (m + n))
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
    }*/ 

    // T: O(m + n) - Binary Euclidean Algorithm log(m*n)
    // S: O(m + n) - Compare 2 concatenations of lengths
    // GCD
    std::string gcdOfStrings(std::string str1, std::string str2) {
        // Check concatenations of str1 and str2 
        if(str1 + str2 != str2 + str1){
            return "";
        }

        // Get the GCD of the two lengths
        int gcdLength = gcd(str1.length(), str2.length());

        // Return the prefix string with a length of gcdLength of either str1 or str2
        return str1.substr(0, gcdLength);
    }
};