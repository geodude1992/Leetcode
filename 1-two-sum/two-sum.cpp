class Solution {
public:
    /*Brute force O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        // loop 
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    // return {i, j}
                    return result;
                }
            }
        }
        return {};
    }*/ 

    // One-Pass Hashmap
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hmap;

        // Iterate through the array and insert to hashmap simultaneously
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            //if(hmap.find(complement) != hmap.end()){
            if(hmap.count(complement)){
                result.push_back(i);
                result.push_back(hmap[complement]);
                return result;
                //return {i, hmap[complement]};
            }
            hmap[nums[i]] = i;
        }
        return {};
    }
};