#include <algorithm>
class Solution {
public:
    // The std::min_element() in C++ is an STL algorithm that is used to find the minimum element in a given range. 
    // This range can be array, vector, list or any other container. It is defined inside the <algorithm> header file
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; ++i){
            // std::min_element(first, last, comp);
            /*
            first: Iterator to the first element of the range.
            last: Iterator to the element just after the last element of the range.
            comp: Binary function, functor or lambda expression that compares two elements in the range. 
            By default, it is set as < operator.
            */
            auto minItr = std::min_element(nums.begin(), nums.end());
            *minItr *= multiplier;
        }
        return nums;
    }
};