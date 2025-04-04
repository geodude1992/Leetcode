class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> evenHeap;
        priority_queue<int> oddHeap;
        string nums = to_string(num);
        int ans = 0;

        for(int i = 0; i < nums.size(); ++i){
            int digit = nums[i] - '0';
            if(digit % 2) evenHeap.push(digit);
            else oddHeap.push(digit);
        }

        for(int i = 0; i < nums.size(); ++i){
            ans = ans * 10;
            if((nums[i] - '0') % 2) {
                ans += evenHeap.top(); evenHeap.pop();
            } else {
                ans += oddHeap.top(); oddHeap.pop();
            }
        }
        return ans;
    }
};