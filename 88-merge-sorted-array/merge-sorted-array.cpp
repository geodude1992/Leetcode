class Solution {
public:
    // Using STL
    // T: O(m+n log m+n) - due to sort() function
    // S: O(1) - no extra space is used
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Traverse through nums2 and append its elements to the end of nums1 starting from index m.
        for(int i = m, j = 0; j < n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        // Sort the entire nums1 array using sort() function.
        sort(nums1.begin(), nums1.end());
    }
};