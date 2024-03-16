class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Brian Kernighan's Algorithm
        while(left < right){
            // turn off rightmost 1-bit and apply AND operation between the reduced right val and left val to obtain the common prefix
            right = right & (right - 1);
        }
        return left & right;
    }
};