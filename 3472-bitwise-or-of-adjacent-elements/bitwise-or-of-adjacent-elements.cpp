class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        vector<int> result;
        
        for(int i = 1; i < nums.size(); ++i){
            result.push_back(nums[i] | nums[i - 1]);
        }

        return result;
    }
};