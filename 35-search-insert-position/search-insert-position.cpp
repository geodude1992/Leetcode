class Solution {
public:
    // Binary Search
    // T: O(logn)
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        // Special Case where target is greater than all numbers in array
        if(target > right) return right + 1;
        
        // return where target would be if missing
        return left;
    }
};