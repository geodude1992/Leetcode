class Solution {
public:
    // Greedy Solution
    // T: O(n) - 
    // S: O(1) - 
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;
        // Iterate from 1st index to the 3rd to last index.. we dont touch the last two indices
        for(int i = 0; i < n - 2; ++i){
            // Check our first position 
            if(nums[i] == 0){
                nums[i] = 1;
                nums[i + 1] = 1 ? nums[i + 1] == 0 : 1; 
                nums[i + 2] = 1 ? nums[i + 2] == 0 : 1; 
                flips++;
            }
        }

        //if(nums[n-2]==1 & nums[n-1]==1) return flips;
        //return -1;
        // if(x) ?(return) flips :(else) -1
        return (nums[n-2]==1 & nums[n-1]==1) ? flips : -1;
    }
};