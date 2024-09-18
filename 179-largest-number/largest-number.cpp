class Solution {
    // Compare a+b and b+a is the key, greedy approach of comparing pairs of numbers leads to correct result
public:
    // Approach 1: Built-in Function 
    // T: O(n log n) - Sorting most time consuming | S: O(n + S) - n is sorted array, S is the sorting algo
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        // Convert each integer to a string
        for(int n : nums){
            numStrings.push_back(to_string(n));
        }

        // Sort strings based on concatenated values
        sort(numStrings.begin(), numStrings.end(), 
            [](string &a, string &b) { return a + b > b + a; });

        // Handle the case where the largest number is zero
        if(numStrings[0] == "0") return "0";

        // Concatenate sorted strings to form the largest number
        string largestNum;
        for(string &numStr : numStrings){
            largestNum += numStr;
        }
        return largestNum;
    }

};