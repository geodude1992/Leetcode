class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        // Use a min heap to store numbers in ascending order
        priority_queue<int, vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());
        vector<int> result;

        // Iterate through num length / 2 times since we are add 2 elements per iteration
        // Or increment i by 2 each iteration
        for(int i = 0; i < nums.size() / 2; i++){
            int a = minHeap.top(); minHeap.pop();
            int b = minHeap.top(); minHeap.pop();

            result.push_back(b);
            result.push_back(a);
        }
        return result;
    }
};