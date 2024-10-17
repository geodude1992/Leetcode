class CustomStack {
public:
    // Arrays with Lazy Propagation, a technique where updates are delayed until absolutely necessary.
    // T: O(1) push, pop, inc | S: O(2 * maxSize) == O(maxSize)
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
    
    // When popping an element, we return the value at the top of the stack, including any increments that apply to it.
    // This is where lazy propagation is used.
    int pop() {
        // Check if stack is empty if so return -1
        if(topIndex < 0){
            return -1;
        }
        // Calculate the actual value with increment
        int result = stacc[topIndex] + increments[topIndex];

        // Propagate the increment to the element below the element being popped
        // Preserving the necessary increments for future pops.
        if(topIndex > 0) increments[topIndex - 1] += increments[topIndex];

        // Reset the increment for this position
        increments[topIndex] = 0;
        
        // Then, we decrement topIndex to remove the current top element.
        topIndex--;

        return result;
    }
    
    // Instead of directly modifying the bottom k elements, we simply update the value at index k-1 in incrementArray
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