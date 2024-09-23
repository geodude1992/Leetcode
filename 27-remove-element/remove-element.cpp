class Solution {
public:
    // T: O(n) | S: O(1)
    // Intuition behind this solution is to iterate through the array and keep track of two pointers: index and i
    int removeElement(vector<int>& nums, int val) {
        // Represents the current position for the next non-target element.
        int index = 0;
        // Iterate through each element of the input array using the i pointer.
        for(int i = 0; i < nums.size(); i++){
            // If nums[i] is not equal to val, it means it is a non-target element.
            if(nums[i] != val){
                // Set nums[index] to nums[i] to store the non-target element at the current index position.
                nums[index] = nums[i];
                // Increment index by 1 to move to the next position for the next non-target element.
                index++;
            }
        }
        // Represents the length of the modified array.
        return index;
    }
};