class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while(x != 0){ //123
            int last = x % 10; // 3, 2, 1
            rev = (rev * 10) + last; // 3, 30 + 2, 320 + 1
            x = x / 10; // 12, 1, 0      
        }
        return (rev > INT_MAX || rev < INT_MIN)? 0 : rev;
    }
};