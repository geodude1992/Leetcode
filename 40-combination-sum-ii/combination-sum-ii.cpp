class Solution {
public:
    // Backtracking Solution with Sorted input array
    // T: O(n * 2^n) - O(n)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentComb;
        // Sort nums
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, currentComb, result);
        return result;
    }

    void backtrack(int idx, vector<int>& candidates, int target, vector<int>& currentComb, vector<vector<int>>& result){
        // Sum(combset) == target
        if(target == 0){
            result.push_back(currentComb);
            return;
        }else if(target < 0) return;// Current combination subset sum is greater than out target
        
        for(int i = idx; i < candidates.size(); ++i){
            // Check for duplicate and ignore it, if current idx is equal to previous idx and i is not the current idx
            if(i != idx && candidates[i] == candidates[i - 1]) continue;
            currentComb.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], currentComb, result);
            currentComb.pop_back();
        }
    }
};