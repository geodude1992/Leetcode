#include <algorithm>
class Solution {
public:
    // min_element Solution
    // T: O(K * N)
    // The std::min_element() in C++ is an STL algorithm that is used to find the minimum element in a given range. 
    // This range can be array, vector, list or any other container. It is defined inside the <algorithm> header file
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // 1. Iterate through the array k times
        for(int i = 0; i < k; ++i){
            // std::min_element(first, last, comp);
            /*
            first: Iterator to the first element of the range.
            last: Iterator to the element just after the last element of the range.
            comp: Binary function, functor or lambda expression that compares two elements in the range. 
            By default, it is set as < operator.
            */
            // 2. Find the index of the minimum element in the current array
            auto minItr = std::min_element(nums.begin(), nums.end());
            // 3. Multiply the minimum element by the given multiplier
            *minItr *= multiplier;
        }
        return nums;
    }
};