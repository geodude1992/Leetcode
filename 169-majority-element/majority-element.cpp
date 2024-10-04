class Solution {
public:
    // Brute force
    // T: O(n^2) - nested loop
    // S: O(1)
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2;
        int count;
        int ans;
        for(int num : nums){
            count = 0;
            for(int n : nums){
                if(num == n){
                    count++;
                }
            }
            if(count > majorityCount) return num;
        }
        return -1;
    }
};