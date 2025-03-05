class Solution {
public:
    // Min-Heap Solution - Heap with smallest among them at the top, then pop the heap for k-1. Target will be top element
    // T: O()
    // S: O()
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<T, Container, Compare> ... T the data type stored in pq, Container: the storeage used, Comparision function detering order
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};