class Solution {
public:
    // Cantors Diagonal 
    // T: O(n) - Iterate through nums once
    // S: O(1) - No extra memory, answer string is neglected
    string findDifferentBinaryString(vector<string>& nums) {
        string answer = "";
        for(int i = 0; i < nums.size(); ++i){
            char current = nums[i][i];
            if (current == '0') answer += '1';
            else answer += '0';
        }
        return answer;
    }
};