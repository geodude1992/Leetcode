class Solution {
public:
    // T: O(n) S: O(1)
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int cur = 0; cur <=  nums.size()-1; cur++){
            if(nums[cur] != 0) {
                swap(nums[slow], nums[cur]); 
                slow++;
            }
        }
    }
};