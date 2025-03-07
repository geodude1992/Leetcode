class Solution {
public:
    // Sieve of Eratosthenes - Efficient for finding prime numbers in a range
    // T: O(right * log(log(right)))
    // S: O(right)
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, true);
        vector<int> primeNums;
        vector<int> result = {-1, -1};

        sieve[0] = sieve[1] = false;

        // Store all the prime values from 0 till right
        // Using sieveOfEratosthenes method to to find the  prime numbers
        for(int i = 2; i * i <= right; ++i){
            if(sieve[i]){
                for(int j = i * i; j <= right; j += i){
                    sieve[j] = false;
                }
            }
        }
        
        // Store all prime numbers in primeNums
        for(int i = left; i <= right; ++i){
            if(sieve[i]){
                primeNums.push_back(i);
            }
        }

        //If size of primeNumbers is less then 2, then the output will be [-1, -1]
        //Even if there is 1 prime number between left & right, because res[1] - res[0] should still be minimized.
        if(primeNums.size() < 2) return result;

        //If primeNumbers contains only 2 values, then no other combination exists
        if(primeNums.size()==2) return primeNums;

        //Check the minimum difference between 2 prime numbers
        int min_gap = INT_MAX;
        for(int i = 1; i < primeNums.size(); ++i){
            int gap = primeNums[i] - primeNums[i - 1];
            if(gap < min_gap){
                min_gap = gap;
                result = {primeNums[i - 1], primeNums[i]};
            }
        }
        return result;
    }
};