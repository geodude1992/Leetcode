class Solution {
public:
    // Sliding Window Solution
    // T: O(N)
    // S: O(1)
    int minimumRecolors(string blocks, int k) {
        int l = 0, whiteCells = 0, minOps = INT_MAX;

        // Move right ptr
        for(int r = 0; r < blocks.size(); ++r){
            // Increment white cell count. if r ptr is white
            if(blocks[r] == 'W') whiteCells++;

            // k consecutive elements are found
            if(r - l + 1 == k){
                // update min
                minOps = min(minOps, whiteCells);
                
                /* HANDLE LEFT PTR WHEN MOVING RIGHT*/
                // Decrement white cell count if left ptr is white
                if(blocks[l] == 'W') whiteCells--;

                // Move l ptr
                l++;
            }
        }
        return minOps;
    }
};