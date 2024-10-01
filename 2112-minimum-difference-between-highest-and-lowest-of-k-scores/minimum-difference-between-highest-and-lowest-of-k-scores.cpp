class Solution {
public:
    // Sort numbers, 2 Pointers placed at 0th Position and (0+k-1)th Position and take the difference of both and continue the same process until array is finished.
    // k chosen scores need to be as close possible to each other
    // T: O(n logn) - sort takes logn, linear iteration
    // S: O(1)
    int minimumDifference(vector<int>& nums, int k) {
        int left = 0, right = k - 1;
        sort(nums.begin(), nums.end());
        int answ = INT_MAX;
        while(right < nums.size()){
            answ = min(answ, nums[right] - nums[left]);
            right++;
            left++;
        }
        return answ;
    }
};