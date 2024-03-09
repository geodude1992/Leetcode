/*  HashSet Solution
    Time Complexity O(n + m)
        Creating HashSet takes O(n)
    Space Complexity O(n)

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // add elements from nums 1 to hashset
        unordered_set<int> set1(nums1.begin(), nums1.end());

        // Search for each element of nums2 in hashset1
        // Return the first common element found
        for(int num : nums2){
            if(set1.contains(num)){
                return num;
            }
        }
        //return -1 if there is no common element(s)
        return -1;
    }

*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Binary Search should be done on the larger array
        // If nums1 is longer, call getCommon with the arrays swapped
        if(nums1.size() > nums2.size()){
            return getCommon(nums2, nums1);
        }

        // Search for each element of nums1 in nums 2
        // Return the first common element found
        for(int num : nums1){
            if(binarySearch(num, nums2)){
                return num;
            }
        }

        // Return -1 if there are no common elements
        return -1;
    }

private:
    bool binarySearch(int target, vector<int>& nums){
        int left = 0;
        int right = nums.size() -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{ // nums[mid] == target
                return true;
            }
        }
        return false;
    }
};