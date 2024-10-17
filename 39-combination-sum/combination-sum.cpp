class Solution {
public:
    // Backtracking Solution
    // T: O(n^((t/n)+1)) | S: O(t/m)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combinations;
        // starting index 0
        backtrack(0, candidates, target, combinations, result);
        return result;
    }

    void backtrack(int idx, vector<int>& candidates, int target, vector<int>& combinations, vector<vector<int>>& result){
        // Once we have a sum(comb) == target
        if(target == 0){
            result.push_back(combinations);
            return;
        }else if(target < 0){
            // Current combination subset sum is greater than out target
            return;
        }

        for(int i = idx; i < candidates.size(); ++i){
            // Add current idx value to our combinations subset
            combinations.push_back(candidates[i]);
            // Run backtracking on cur comb subset with new target set to target - cand[i] 
            backtrack(i, candidates, target - candidates[i], combinations, result);
            // Remove last number
            combinations.pop_back();
        }
    }
};