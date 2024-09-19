class Solution {
public:
    // T: O(n) S: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        // Initialize vector of nums length filled with 1's
        vector<int> result(nums.size(), 1);

        // Get product value of every element that comes before a given element, for each element
        int leftProduct= 1;
        // iterate through the array and multiple all elements
        for(int i = 0; i < nums.size(); i++){
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        // Get the product value of every element after a given element, for each element
        int rightProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--){  // Start at len(nums) - 1 since 0th index array
            result[i] *= rightProduct;
            // multiple the left and right products of each element
            rightProduct *= nums[i];
        }
        
        return result;
    }
};