class Solution {
public:
    // divisible Help function modulus 10 math solution
    // T: O(n * d)
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; ++i){
            if(isDivisible(i)) result.push_back(i);
        }
        return result;
    }

    bool isDivisible(int n){
        int num = n;
        while(num!=0){
            int lastdigit = num % 10;
            if(lastdigit == 0 || n % lastdigit != 0) return false;
            num /= 10;
        }
        return true;
    }
};