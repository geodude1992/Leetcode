class Solution {
public:
    /* DFS
    // T: O(n) - Generating all numbers from 1 to n in lexicographical order.
    // S: O(log(base 10)n) - 
    vector<int> lexicalOrder(int n) {
        vector<int> lexinums;
        // Generate numbers from 1 to 9
        for(int i = 1; i <= 9; i++){
            dfs(i, n, lexinums);
        }
        return lexinums;
    }

    void dfs(int current, int limit, vector<int>& result){
        // If the current number exceeds the limit, stop recursion
        if(current > limit) return;
        // Add the current number to the result
        result.push_back(current);
        // Try to append digits from 0 to 9 to the current number
        for(int nextDigit = 0; nextDigit <= 9; nextDigit++){
            int nextNumber = current * 10 + nextDigit;
            // If the next number is within the limit, continue recursion
            if(nextNumber <= limit){
                dfs(nextNumber, limit, result);
            }else{
                break; // No need to continue if nextNumber exceeds limit
            }
        }
    }*/
    // Iterative
    // T: O(n) - Generating all numbers from 1 to n in lexicographical order.
    // S: O(1) - 
    vector<int> lexicalOrder(int n) {
        vector<int> lexinums;
        int current = 1;

        while(lexinums.size() < n){
            // In each iteration add current number to result array
            lexinums.push_back(current);

            // If current * 10 is less than n we add it to result array
            if(current * 10 <= n){
                current *= 10;
            }else{
                // if current ends with a 9 or next leaf divide by 10 and move up a level, remove last digit
                while(current >= n || current % 10 == 9){
                    current /= 10;
                }
                // Increment current num if current * 10 is greater than n
                current += 1;
            }
        }
        return lexinums;
    }
};