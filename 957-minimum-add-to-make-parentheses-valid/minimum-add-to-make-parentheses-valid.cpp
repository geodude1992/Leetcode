class Solution {
public:
    /** Tip: Parenthesis Matching: Use stack for storing open '(' */

    /*  Stack Solution - Not efficient since we only have one type of parenthesis
        T: O(n) - traverse string
        S: O(n) - stack mem used
    *
    int minAddToMakeValid(string s) {
        stack<char> Stac;
        int count = 0;
        for(char ch : s){
            // Store Open Parenthesis in stack
            if(ch == '(') Stac.push(ch);
            // If char is a Closing Parenthesis increment count var is no Open Parenthesis is in Stack otherwise Pop
            else{
                if(Stac.empty()) count++;
                else Stac.pop();
            }
        }
        // Return Count of Close Parenthesis needing a Open and Size of Stack
        return count + Stac.size();
    }*/


    /*  Counter Solution
        T: O(n) - traverse string
        S: O(1)
    */
    int minAddToMakeValid(string s) {
        int openCount = 0, minRequired = 0;

        for(char ch : s){
            // Instead of pushing to a stack we increment count
            if(ch == '(') openCount++;
            else{
                // Else Close encountered, Decrement openCount if > 0 or increment minRequired
                openCount > 0 ? openCount-- : minRequired++;
            }
        }
        return openCount + minRequired;
    }
};