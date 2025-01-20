class Solution {
public:
    /* 
    nums = [1,3,5] = [0001, 0011, 0101]
    1 => 0001 
    3 => 0011
    res = [0011, ...]
    3 => 0011
    5 => 0101
    res = [0011, 0111]

    T: O(n)
    */
    vector<int> orArray(vector<int>& nums) {
        vector<int> result;
        
        // Range (O, n-2)
        for(int i = 0; i < nums.size()-1; ++i){
            result.push_back(nums[i] | nums[i + 1]);
        }

        return result;
    }
};