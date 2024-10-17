class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long reverse = 0, remainder = 0, temp = x;
        
        while(temp != 0){
            remainder = temp % 10;
            reverse = (reverse * 10) + remainder;
            temp /= 10;
        }
        return reverse == x;
    }
};