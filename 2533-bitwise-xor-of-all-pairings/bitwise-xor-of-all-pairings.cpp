class Solution {
public:
    /*  Three useful properties of XOR:
        a XOR b = b XOR a
        a XOR a = 0
        a XOR 0 = a

        XOR is Commutative. *Order doesnt matter*

        result  = (a1 ^ b1) ^ (a1 ^ b2) ^ (a2 ^ b1) ^ (a2 ^ b2) 
                = (a1 ^ a1 ^ ... repeated n2 times) ^ (a2 ^ a2 ^ ... repeated n2 times) ^ 
                    (b1 ^ b1 ^ ... repeated n1 times) ^ (b2 ^ b2 ^ ... repeated n1 times

        Each element of nums1 appears nums2.size() times in the calculation. And Vice Versa.


        XOR of a number even times is always 0.             i.e.    a ^ a = 0
        XOR of a number odd times is always the number.         a ^ a ^ a = a
    */
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // XOR result of input arrays
        int ans = 0;

        // Get lengths of both arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // If nums2 length is odd, each num in num1 appears odd times in result
        if(len2 % 2 != 0){
            for(int num : nums1){
                ans ^= num;
            }
        }

        // If nums1 length is odd, each num in num2 appears odd times in result
        if(len1 % 2 != 0){
            for(int num : nums2){
                ans ^= num;
            }
        }

        // Return XOR Result
        return ans;
    }

    /* Bruteforce 
        T: O(n^2)
        S: O(n) - n
    
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int ans;

        for(int n : nums1){
            for(int num : nums2){
                nums3.push_back(n ^ num);
            }
        }

        for(int i = 1; i < nums3.size(); ++i){
            if(i == 1) {
                ans = (nums3[i] ^ nums3[i-1]);
            }
            else ans ^= nums3[i];
        }

        return ans;
    }*/
};