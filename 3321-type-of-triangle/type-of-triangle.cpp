class Solution {
public:
    // T: O(1)
    // S: O(1)
    string triangleType(vector<int>& nums) {
        // Check if triangle is equilateral
        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        // Check if triangle is equilateral
        else if((nums[0] == nums[1] && (nums[0] + nums[1] > nums[2])) || 
                (nums[1] == nums[2] && (nums[1] + nums[2] > nums[0])) || 
                (nums[0] == nums[2] && (nums[0] + nums[2] > nums[1])))
            return "isosceles";
        else if((nums[0] + nums[1] > nums[2]) && (nums[1] + nums[2] > nums[0]) && (nums[0] + nums[2] > nums[1]))
            return "scalene";

        return "none";
    }
};