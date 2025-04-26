class Solution {
public:
    /* DP Solution O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] represents the length of the longest increasing subsequence that ends with the ith element.
        vector<int> dp(nums.size(), 1);

        // Starting at index 1 check all the index before it
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                // valuate its in increasing order
                if(nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }*/

    // Add to Array or replace in Array Solution O(n^2)
    int lengthOfLIS(vector<int>& nums){
        // Initialize a subarray of length one and fill that slot with the first element in nums
        vector<int> subarray(1, nums[0]);

        for(int i = 1; i < nums.size(); ++i){
            int n = nums[i];
            // if n is greater than the last element in the subarray, then add n to subarray
            if(n > subarray[subarray.size() - 1]) subarray.push_back(n);
            else{
                // Find first element in sub array that is greater than or equal to n
                // OPTIMIZE: incorporate Binary search instead for nlogn 
                int j = 0;
                while(n > subarray[j]){
                    j += 1;
                }
                subarray[j] = n;
            }
        }   
        return subarray.size();
    }
};