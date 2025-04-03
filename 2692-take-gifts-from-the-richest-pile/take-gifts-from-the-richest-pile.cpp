 #include <cmath> // library for sqrt function

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Sort numbers in descending order
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        long long giftsLeft = 0;

        for(int i = 0; i < k; ++i){
            int sqroot = sqrt(maxHeap.top()); maxHeap.pop();
            maxHeap.push(sqroot);
        }
        for(int i = 0; i < gifts.size(); ++i){
            giftsLeft += maxHeap.top(); maxHeap.pop();
        }
        
        return giftsLeft;
    }
};