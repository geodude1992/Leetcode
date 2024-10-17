class Solution {
public:
    // Backtracking DFS
    // T: O(N*2^n) - generate all subsets and copy them into the result array | S: O(n) current and modifying in place
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        // Our current subset we modify in-place using backtracking, initially empty
        vector<int> currentSubset;
        // Pass first index 0
        backtrackdfs(0, nums, currentSubset, result);
        return result;
    }

    void backtrackdfs(int idx, vector<int>& nums, vector<int> current, vector<vector<int>>& result){
        // Push current subset into our result, initially empty list
        result.push_back(current);
        // Iterate over nums
        for(int j = idx; j < nums.size(); ++j){
            // Push idx value into current subset, initialy 0th idx
            current.push_back(nums[j]);
            // Call backtrack on next idx, initially 1st indx bk(1, [1]) ... [1], [1,2], [1,2,3]
            backtrackdfs(j + 1, nums, current, result);
            // remove last element so current = [1, 2], j now increments to 2
            current.pop_back();
        }
    }
};