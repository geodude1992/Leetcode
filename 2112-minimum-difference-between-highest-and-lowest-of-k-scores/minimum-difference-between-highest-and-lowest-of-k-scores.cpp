class Solution {
public:
    // Sort numbers, 2 Pointers placed at 0th Position and (0+k-1)th Position and take the difference of both and continue the same process until array is finished.
    // k chosen scores need to be as close possible to each other
    // T: O(n logn) - sort takes logn, linear iteration
    // S: O(1)
    int minimumDifference(vector<int>& nums, int k) {
        // Initialize pointers. right pointer set to k - 1 as k is <= nums.size()
        int left = 0, right = k - 1;
        sort(nums.begin(), nums.end());
        // Set answer to INT_MAX
        int answ = INT_MAX;
        // Iterate through window using sliding window approach
        while(right < nums.size()){
            // Calculate the difference between the right and left element then update answer with minimum of current value and new calculated difference
            answ = min(answ, nums[right] - nums[left]);
            // Increment both pointers
            right++;
            left++;
        }
        // Return minimum difference
        return answ;
    }
};