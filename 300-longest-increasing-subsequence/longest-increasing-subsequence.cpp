class Solution {
public:
    // DP Solution O(n^2)
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
        /*int lis = 0;
        for(int n : dp){
            lis = max(lis, n);
        }*/
        return *std::max_element(dp.begin(), dp.end());
    }
};