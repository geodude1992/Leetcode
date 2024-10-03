class Solution {
public:
    // Mathy
    // T: O(log(base 10)x)
    // S: O(1)
    int reverse(int x) {
        long rev = 0;
        while(x != 0){ //123
            // Store last number
            int last = x % 10; // 3, 2, 1
            // Add last number to reverse (multiply reverse by 10 after each iteration)
            rev = (rev * 10) + last; // 3, 30 + 2, 320 + 1
            // Reduce original number by removing the last number
            x = x / 10; // 12, 1, 0      
        }
        // Constraints: -2^31 <= x <= 2^(31) - 1.. return 0 if so
        return (rev > INT_MAX || rev < INT_MIN) ? 0 : rev;
    }
};