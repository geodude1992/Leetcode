class Solution {
public:
    // T: O(n) | S: O(1)
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;

        string temp = "";
        
        for(int i = 0; i < n; i++){
            // Declare another pointer
            int j = i;
            // Run that pointer until our range does not break
            while(j + 1 < n && nums[j + 1] == nums[j] + 1){
                j++;
            }
            // If j > i, that means we ot our range more than one element
            if(j > i){
                temp += to_string(nums[i]); // first store starting point
                temp += "->"; // then store arrow
                temp += to_string(nums[j]); // Lastly store the end point
            }else{ // Single number without previous or next number
                temp += to_string(nums[i]);
            }
            result.push_back(temp); // Push possible answer string to resulting array
            temp.clear(); // temp = "" clear temp string for next range/single number
            i = j; // Move i pointer to j postion for new start
        }
        return result;
    }
};