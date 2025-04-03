class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int &st : stones){
            maxHeap.push(st);
        }

        while(maxHeap.size() > 1){
            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();
            if(x == y) continue;
            else{
                int ny = y - x;
                maxHeap.push(ny);
            }
        }
        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};