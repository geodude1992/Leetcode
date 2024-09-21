class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexinums;
        // Generate numbers from 1 to 9
        for(int current = 1; current <= 9; current++){
            dfs(current, n, lexinums);
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
    }
};