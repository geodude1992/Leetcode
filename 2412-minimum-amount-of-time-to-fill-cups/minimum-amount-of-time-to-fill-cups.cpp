class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> maxHeap(amount.begin(), amount.end());
        int seconds = 0;
        while(maxHeap.top() != 0){
            int cup1 = maxHeap.top(); maxHeap.pop();
            int cup2 = maxHeap.top(); maxHeap.pop();
            maxHeap.push(--cup1);
            maxHeap.push(--cup2);
            seconds++;
        }
        return seconds;
    }
};