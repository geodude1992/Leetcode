class MovingAverage {
    /** Queue - Pop from front when size == queue size (window) and add from rear end */
    double windowSum = 0;
    int window;
    queue<double> numQueue;

public:
    MovingAverage(int size) {
        window = size;
    }
    
    double next(int val) {
        if(numQueue.size() == window){
            windowSum -= numQueue.front();
            numQueue.pop();
        }
        numQueue.push(val);
        windowSum += val;
        return windowSum / numQueue.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */