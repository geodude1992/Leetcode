class Solution {
public:
    /* O(1) space, and O(n) time
    Put each number in its right place.
    For example:
    When we find 5, then swap it with A[4].
    At last, the first place where its number is not right, 
    return the place + 1.
    */
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            // Only check +ve numbers from 0 to N and number is not in correct index
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                // swap current index with 
                swap(nums[i], nums[nums[i] - 1]);        
        /* TESTING
        for(int i = 0; i < n; ++i) {
            cout << nums[i]<<endl;
        }  */
        for(int i = 0; i < n; ++i)
            // Checks if the current index has a value that is in the incorrect spot
            // return that missing value
            if(nums[i] != i + 1) 
                return i + 1;

        return n + 1;
    }
};