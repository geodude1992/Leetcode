class Solution {
public:
    // Brute force
    // T: O(n^2) - nested loop
    // S: O(1)
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2;

        for (int num : nums) {
            int count = 0;
            for (int elem : nums) {
                if (elem == num) {
                    count += 1;
                }
            }

            if (count > majorityCount) {
                return num;
            }
        }

        return -1;
    }
};