// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Linear Solution
        /*for(int i = 1; i <= n; i++){
            if(isBadVersion(i) == true) return i;
        }
        return false;*/

        // Binary Search Solution O(n*log n)
        int left = 1, right = n;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid) == false) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};