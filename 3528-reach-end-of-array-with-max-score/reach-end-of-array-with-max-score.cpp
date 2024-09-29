// define ll
//# define ll long long

class Solution {
public:
    // USE ll instead of long long int
    // T: O(n)
    // S: O(1)
    long long findMaximumScore(vector<int>& nums) {
        long long answ = 0,  n = nums.size();
        for(long long i = 0, j = 1; j < n; j++){
            if(j == n - 1 || nums[j] > nums[i]){
                answ += (j - i) * nums[i];
                i = j;
            }
        }
        return answ;
    }
};