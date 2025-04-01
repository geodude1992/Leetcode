class Solution {
public:
    // Heap Solution
    // T: O(n * log n)
    // S: O(n)
    long long putMarbles(vector<int>& weights, int k) {
        // k partitions
        long long maxScore = 0;
        long long minScore = 0;

        // We use a max heap and a min heap to add the weight of each pair of adjacent elements to.
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // We keep them as size k to get the k smallest in the max heap and the k largest in the min heap.
        for(int i = 1; i < weights.size(); ++i){
            maxHeap.push(weights[i] + weights[i - 1]);
            minHeap.push(weights[i] + weights[i - 1]);
        }
        
        // k - 1 lines that split the partitions
        for(int i = 0; i < k - 1; ++i){
            minScore += minHeap.top(); minHeap.pop();
            maxScore += maxHeap.top(); maxHeap.pop();
        }
        return maxScore - minScore;
    }
};