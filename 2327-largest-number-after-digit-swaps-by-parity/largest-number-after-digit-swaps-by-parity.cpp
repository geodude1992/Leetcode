class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> evenHeap;   // priority queue to store EVEN digits in descending order
        priority_queue<int> oddHeap;    // priority queue to store ODD digits in descending order
        string nums = to_string(num);   // converting num to a string for easy access of the digits
        int ans = 0;

        for(int i = 0; i < nums.size(); ++i){
            int digit = nums[i] - '0';
            if(digit % 2 == 0) evenHeap.push(digit);
            else oddHeap.push(digit);
        }

        for(int i = 0; i < nums.size(); ++i){
            ans = ans * 10;
            if((nums[i] - '0') % 2 == 0) {
                ans += evenHeap.top(); evenHeap.pop();
            } else {
                ans += oddHeap.top(); oddHeap.pop();
            }
        }
        return ans;
    }
};