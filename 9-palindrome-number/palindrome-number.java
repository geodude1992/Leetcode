class Solution {
    public boolean isPalindrome(int x) {
        int xx = x;
        int revNum = 0;
        int sign = 1;
        if(x < 0) return false;
        while (xx != 0){
            revNum = (revNum * 10) + (xx % 10);
            xx /= 10;
        }
        return x == revNum;
    }
}