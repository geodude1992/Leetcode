 #include <cmath> // library for sqrt function

class Solution {
public:
    // Max Heap Solution
    // T: O(n * logn + k) - initialize k cost n, populating the heap cost logn, k iterations
    // S: O(n) - pq is not used in result
    long long pickGifts(vector<int>& gifts, int k) {
        // Sort numbers in descending order
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        long long giftsLeft = 0;

        // Get Sq Root of each Max element for K seconds and push element back to Heap
        for(int i = 0; i < k; ++i){
            int sqroot = sqrt(maxHeap.top()); maxHeap.pop();
            maxHeap.push(sqroot);
        }
        // Since the size of pq remains the same, we iterate through length of gifts array and add to sum
        for(int i = 0; i < gifts.size(); ++i){
            giftsLeft += maxHeap.top(); maxHeap.pop();
        }
        
        return giftsLeft;
    }
};