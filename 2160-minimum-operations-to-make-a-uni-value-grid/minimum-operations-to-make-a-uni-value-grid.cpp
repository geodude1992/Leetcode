class Solution {
public:
    // Sorted and median
    // T: O(mn*log(mn))
    // S: O(mn)
    int minOperations(vector<vector<int>>& grid, int x) {
        // Turn 2D array into 1D array
        vector<int> nums;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                nums.push_back(grid[r][c]);
            }
        }
        
        // Sort our 1D array
        sort(nums.begin(), nums.end());

        // Store the first element of the sorted array for divisibility check
        int firstElement = nums[0];

        // Find median of sorted array
        int median = nums[nums.size() / 2];

        // Initialize resulting int
        int minOp = 0;

        // Iterated through each element
        for(int i = 0; i < nums.size(); i++){
            // Calculate the difference from the first element to check for divisibility
            int diff = nums[i] - firstElement;

            // If the difference is not divisible by x, return -1 (impossible case)
            if(diff % x != 0) return -1;

            // Update the first element to the current element for the next iteration
            firstElement = nums[i];

            // Calculate the operations needed to convert current element to the median and add total answer
            minOp += (abs(median - nums[i])) / x;
        }
        // return total minimum operations needed
        return minOp;
    }
};