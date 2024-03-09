class Solution {
public:
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
};