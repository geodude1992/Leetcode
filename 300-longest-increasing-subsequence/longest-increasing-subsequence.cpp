class Solution {
public:
    // DP Solution O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                // valuate its in increasing order
                if(nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        int lis = 0;
        for(int c : dp){
            lis = max(lis, c);
        }
        return lis;
    }
};