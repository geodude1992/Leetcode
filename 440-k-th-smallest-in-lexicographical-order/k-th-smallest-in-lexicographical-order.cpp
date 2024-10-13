class Solution {
public:
    /* Array Mathy Solution - MLE (Memory Limit Exceeded)
    // T: O(n)
    // S: O(n)
    int findKthNumber(int n, int k) {
        vector<int> lexinums;
        int current = 1;

        // Generate all numbers from 1 to n
        for(int i = 0; i < n; i++){
            // In each iteration add current number to result array
            lexinums.push_back(current);

            // If current * 10 is less than n we add it to result array
            if(current * 10 <= n){
                current *= 10;
            }else{
                // While current ends with 9 or next leaf divide by 10 and move up a level
                // use if n < 199 else use while since if we are at 1999 -> 199 -> 19
                while(current >= n || current % 10 == 9){
                    // Remove last digit
                    current /= 10;
                }
                // Increment current num if current * 10 is greater than n
                current += 1;
            }
        }
        return lexinums[k-1];
    }*/

    // Prefix Tree - instead of generating numbers and sorting lexi. Use Trees
    // T: O(log(n)^2) - while loop k > 0 runs at O(logn) and count function while loop also runs at O(logn)
    // S: O(1) - constant additional space for variables current, k, step, prefixes
    int findKthNumber(int n, int k) {
        // Initialize current prefix to 1 and decrement k by 1
        int current = 1;
        k--;

        // while k is greater than 0
        while(k > 0){
            // Calculate the number of steps in the subtree rooted at current using count function
            int steps = count(n, current, current + 1);

            // if the number of steps is less than or equal to k, increment current by 1 to move to next prefix and decrement k by number of skipped steps
            if(steps <= k){
                current++;
                k -= steps;
            }// otherwise multiple current by 10 to move to next level and decrement k by 1 to account for current level
            else{
                current *= 10;
                k--;
            }
        }
        // Return the value of current as the kth smallest number in lexicographical order
        return current;
    }

    int count(int n, long prefix1, long prefix2){
        // Initialize steps to 0 to keep track of the count of numbers in the range
        int steps = 0;
        // while prefix1 is less than or equal to n
        while(prefix1 <= n){
            // Add number of ints between prefix1 and prefix2 to steps to ensure the count does not exceed n by capping prefix2 at n + 1 if prefix2 is larger than n
            steps += min((long)(n + 1), prefix2) - prefix1;
            // Multiply prefixes by 10 to move to next level
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};