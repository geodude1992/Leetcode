class Solution {
public:
    // BackTracking
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPerm;
        backtrack(nums, currentPerm, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& currPerm, vector<vector<int>>& result){
        // Push current perm to result it perm.size() == nums.size()
        if(currPerm.size() == nums.size()){
            result.push_back(currPerm);
            return;
        }
        // Loop 1.push 2.bktk 3.pop
        for(int i = 0; i < nums.size(); ++i){
            // Iterate over nums. For each num, if num is not in curr, do the following:
            // Add num to curr and call backtrack(curr), then remove num from curr
            if(find(currPerm.begin(), currPerm.end(), nums[i]) == currPerm.end()){
                currPerm.push_back(nums[i]);
                backtrack(nums, currPerm, result);
                currPerm.pop_back();
            }
        }
    }
};