// Queue Solution
// T: O(1) - No loop in next(val) function
// S: O(N) - N is the size of queue
class MovingAverage {
    /** Queue - Pop from front when size == queue size (window) and add from rear end */
    double windowSum = 0;
    int windowSize;
    queue<double> numQueue;

public:
    MovingAverage(int size) {
        windowSize = size;
    }
    
    double next(int val) {
        // 4. Check if our queue is full
        if(numQueue.size() == windowSize){
            // 5. Subract front element of queue from our window sum
            windowSum -= numQueue.front();
            // 6. Pop from front of queue
            numQueue.pop();
        }
        // 1. First we push the input value in the queue
        numQueue.push(val);
        // 2. Update the window sum
        windowSum += val;
        // 3. Return the Average(sum/size)
        return windowSum / numQueue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */