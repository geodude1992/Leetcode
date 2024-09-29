// define ll
//# define ll long long

class Solution {
public:
    // Maximum Possible Score
    // Result: you finally jump to index 'j' and convert all numbers from i to j-1 as nums[i].
    // Answer is found out by adding the values of the array from index 0 to index array.size()-2.
    // Notice that you can never include the last element of array in your answer.
    // T: O(n)
    // S: O(1)
    long long findMaximumScore(vector<int>& nums) {
        long long answ = 0,  n = nums.size();
        // ll i start at index 0, ll j needs to jump at least to index 1
        for(long long i = 0, j = 1; j < n; j++){
            // if j is at nums.size()-
            if(j == n - 1 || nums[j] > nums[i]){
                answ += (j - i) * nums[i];
                i = j;
            }
        }
        return answ;
    }
};