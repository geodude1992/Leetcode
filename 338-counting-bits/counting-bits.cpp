class Solution {
public:
    /*
     * T: O(n)  S: O(n)
     */
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i <= n; i++){
            // DP with Bit manipulation: # of 1's is i/2 + last bit i
            // bitwise RIGHT shift and AND operations
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
};