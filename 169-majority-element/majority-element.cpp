class Solution {
public:
    /* Brute force
    // T: O(n^2) - nested loop
    // S: O(1)
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2;
        int count;
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
    }*/ 

    // Hashmap - Allows us to count element occurrences efficiently
    // T: O(n) - Traverse nums to add to map, traverse to find element > len(nums)/2
    // S: O(n) - hashmap
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int num : nums){
            if(counts.find(num) == counts.end()){
                counts[num] = 1;
            }else{
                counts[num] += 1;
            }
            for(auto itr : counts){
                if(itr.second > nums.size() / 2) return itr.first;
            }
        }
        return -1;
    }
};