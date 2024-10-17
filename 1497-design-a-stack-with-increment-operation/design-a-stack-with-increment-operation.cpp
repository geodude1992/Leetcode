class CustomStack {
public:
    // Arrays with Lazy Propagation, a technique where updates are delayed until absolutely necessary.
    vector<int> stacc;
    vector<int> increments; // lazy propagation
    // Current top index of the stack
    int topIndex;  

    CustomStack(int maxSize) {
        stacc.resize(maxSize);
        increments.resize(maxSize);
        topIndex = -1;
    }
    
    void push(int x) {
        // Check if stack isnt filled
        if(topIndex < (int)(stacc.size()) - 1){
            stacc[++topIndex] = x;
        }
    }
    
    int pop() {
        // Check if stack is empty if so return -1
        if(topIndex < 0){
            return -1;
        }
        // Calculate the actual value with increment
        int result = stacc[topIndex] + increments[topIndex];

        // Propagate the increment to the element below
        if(topIndex > 0) increments[topIndex - 1] += increments[topIndex];

        // Reset the increment for this position
        increments[topIndex] = 0;
        
        topIndex--;

        return result;
    }
    
    void increment(int k, int val) {
        if(topIndex >= 0){
            int incrementIdx = min(topIndex, k - 1);
            increments[incrementIdx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */