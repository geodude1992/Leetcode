class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // O(NlogN) time / O(1) space
        for (auto &x : nums) x *= x;
        sort(nums.begin(), nums.end());
        return nums;
    }
};