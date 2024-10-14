class Solution {
public:
    int rotatedDigits(int n) {
        int goodInts = 0;
        for(int i = 1; i <= n; i++){
            if(check(i) == 0) continue;
            else goodInts++;
        }
        return goodInts;
    }

    int check(int num){
        int count = 0;
        while(num > 0){
            int rem = num % 10;
            if(rem == 3 || rem == 4 || rem == 7) return 0;
            if(rem == 5 || rem == 2 || rem == 6 || rem == 9) count++;
            num /= 10;
        }
        return count;
    }
};