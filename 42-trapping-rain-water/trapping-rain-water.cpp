class Solution {
public:
    /* Brute Force (TLE) - for each element check heights on both sides, get minimum of max heights and subtract from current element height
    // T: O(n^2) - for each element of array, we iterate both sides
    // S: O(1) - no extra space used
    int trap(vector<int>& height) {
        int result = 0;
        // Start from second element so we dont go OOB comparing the left side
        for(int i = 1; i < height.size() - 1; i++){
            int left_max = 0, right_max = 0;

            // Search the left side for max bar size
            for(int j = i; j >= 0; j--){
                left_max = max(left_max, height[j]);
            }
            // Search the right side for max bar size
            for(int j = i; j < height.size(); j++){
                right_max = max(right_max, height[j]);
            }
            result += min(left_max, right_max) - height[i];
        }
        return result;
    }*/

    /* DP - Store max heights from both sides
    // T: O(n) - Store the max heights upto a point using 2 iterations
    // S: O(n) - additional space for left/right_max arrays
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int result = 0;
        // Store max heights
        vector<int> left_max(height.size()), right_max(height.size());

        left_max[0] = height[0];
        // Search left side
        for(int i = 1; i < height.size(); i++){
            left_max[i] = max(height[i], left_max[i-1]);
        }
        // Search right side
        right_max[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for(int i = 1; i < height.size() - 1; i++){
            result += min(left_max[i], right_max[i]) - height[i];
        }
        return result;
    }*/

    // Using Stacks - 
    // T: O(n) - each bar can be touched at most twice(insertation and deletion, O(1))
    // S: O(n0 - Stack can take upto O(n), stairs or flat array
    int trap(vector<int>& height) {
        // Use stack to store the indices of the bars
        int result = 0, current = 0;
        stack<int> stacc;

        while(current < height.size()){
            // Iterate the array while stack is not empty and height[cur] > height[stack.top()]
            while(!stacc.empty() && height[current] > height[stacc.top()]){
                // stack element can be popped
                int top = stacc.top();
                stacc.pop();
                if(stacc.empty()) break;

                // Find distance between the current element and th element at the top of stack
                int distance = current - stacc.top() - 1;

                // Find the bounded height
                int bounded_height = min(height[current], height[stacc.top()]) - height[top];

                // Add resulting trapped water
                result += distance * bounded_height;
            }
            // Push current index to top of the stack
            stacc.push(current++);
        }
        return result;
    }
};