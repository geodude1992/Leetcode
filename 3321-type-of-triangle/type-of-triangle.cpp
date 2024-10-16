class Solution {
public:
    // T: O(1)
    // S: O(1)
    string triangleType(vector<int>& nums) {
        // Check if triangle is Equilateral
        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        // Check if triangle is Isosceles - ANY two lengths of equal size AND their sum is greater than the third length
        else if((nums[0] == nums[1] && (nums[0] + nums[1] > nums[2])) || 
                (nums[1] == nums[2] && (nums[1] + nums[2] > nums[0])) || 
                (nums[0] == nums[2] && (nums[0] + nums[2] > nums[1])))
            return "isosceles";
        // Check if triangle is Scalene - sum of ALL two lengths is greater than the third length
        else if((nums[0] + nums[1] > nums[2]) && (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1]))
            return "scalene";

        return "none";
    }
};