class Solution {
    vector<int> duplicates;
public:
    // Time Complexity: O(n) where n is size of input array
    // Space Complexity: O(1)
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