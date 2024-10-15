class Solution {
public:
    // Backtracking Solution - Base Case and Conditions
    // T: O(kn^k) = k(n!/(n-k)! k!)
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combK;
        backtrack(1, n, k, combK, result);
        return result;
    }

    void backtrack(int startidx, int n, int k, vector<int>& combK, vector<vector<int>>& result){
        // Base Case: Every backtrack problem has a base case which tells use when to stop with recursion process
        // Base Case: Size of Array current == k we stop
        if(combK.size() == k){
            result.push_back(combK);
            return;
        }
        for(int i = startidx; i <= n; i++){
            combK.push_back(i);   // Add current element to our array of combinations
            backtrack(i+1, n, k, combK, result);  // Recursively call backtrack, continue adding values till arr.len == k
            combK.pop_back();     // Proceed to next element but first remove current element
        }
    }
};