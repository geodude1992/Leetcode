class Solution {
public:
    // Monotonically Decreasing Queue
    // add and remove from deque takes O(1)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deq;    // efficiency
        int arrLen = nums.size();

        for(int start = 0; start < arrLen; start++){
            // If the deque head is out of the window then pop head
            if(deq.size() > 0 && deq.front() <= start - k) deq.pop_front();

            // If the deque is non empty and current val in nums >= last element of deque
            // then remove all elements are <= from back
            while(deq.size() > 0 && nums[start] >= nums[deq.back()]){
                deq.pop_back();
            }

            // insert elements from nums to the back of deque
            deq.push_back(start);

            // Store results from the end of the first window
            if(start + 1 >= k) result.push_back(nums[deq.front()]);
        }
        return result;
    }
};