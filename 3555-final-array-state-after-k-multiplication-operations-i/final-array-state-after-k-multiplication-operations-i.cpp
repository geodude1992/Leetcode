#include <algorithm>
class Solution {
public:
    // min_element Solution
    // T: O(K * N)
    // The std::min_element() in C++ is an STL algorithm that is used to find the minimum element in a given range. 
    /* This range can be array, vector, list or any other container. It is defined inside the <algorithm> header file
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // 1. Iterate through the array k times
        for(int i = 0; i < k; ++i){
            // 2. Find the index of the minimum element in the current array
            auto minItr = std::min_element(nums.begin(), nums.end());
            // 3. Multiply the minimum element by the given multiplier
            *minItr *= multiplier;
        }
        return nums;
    }*/
    // minHeap Solution
    // T: O(nlogn + klogn)
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Iterate through nums array to store elements with their indices in pq
        for(int i = 0; i < nums.size(); ++i){
            //minHeap.push({nums[i], i});
            minHeap.emplace(nums[i], i);    // Optimized
        }
        for(int i = 0; i < k; ++i){
            auto it = minHeap.top(); minHeap.pop();
            int element = it.first;
            int idx = it.second;
            // update value in nums array and emplace updated value back in minHeap
            nums[idx] = multiplier * element;
            //minHeap.push({multiplier * element, idx});
            minHeap.emplace(multiplier * element, idx); // Optimized; more efficient because it avoids an extra copy or move.
        }
        return nums;
    }
};