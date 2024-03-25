class Solution {
    vector<int> duplicates;
public:
    /*  Time Complexity: O(n) where n is size of input array
        Space Complexity: O(1)
        Algorithm:
            1. Scan every element in array.
            2. Negate the value at index of ((absolute value of scanned element) - 1)).
            3. Now check if the value a the index is +ve or not. If positive its a duplicate element .

    */
    vector<int> findDuplicates(vector<int>& nums) {
    for(int i=0; i < nums.size(); i++)
        { 
            // evaluate index of selected element if array would have been sorted..
            int indexOfElem = abs(nums[i]) - 1;
            
            // negate the element
            nums[indexOfElem] = - nums[indexOfElem];
            
            // if this element is positive means double negation had happened which 
            // means we editied this element twice.
            if(nums[indexOfElem] > 0)
                duplicates.push_back(indexOfElem + 1);
            
        }
        return duplicates; 
    }
};