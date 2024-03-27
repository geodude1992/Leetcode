class Solution {
public:
    /**
    Intuition :
        1. The intuition was to use sliding window to check all the possible subarrays
        2. In each window having product less than K , add the total possible subarrays to ans
        3. keep increasing the wwindow until product <k and keep storing the ans
        4. Once the product becomes>=k , keep removing the products from the front of window , 
            until it again becomes less than k.

    Complexity
        Time complexity:O(N)
        Space complexity:O(1)
    */
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        long prod = 1;
        int count = 0;   // count of subarray prod  less than k

        if(k<=1) return 0;   // base case

        for(int end = 0; end < nums.size(); end++){
            prod *= nums[end];
    
            while(prod >= k && start < nums.size()){
                prod = prod/nums[start];    // divide product by nums at start pointer t reduce the prod
                start++;    //move start pointer because no longer nums at start can give us prod < k
            }

            if(prod < k)
                // continue calculating the answer until prod>=k
                count += end - start + 1;
        }
    return count;
    }
};