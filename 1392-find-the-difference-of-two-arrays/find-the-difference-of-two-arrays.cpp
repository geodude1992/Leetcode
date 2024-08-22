class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1; //set1(nums1.begin(), nums1.end());
        unordered_set<int> set2; //set2(nums2.begin(), nums2.end());
        vector<vector<int>> result(2);
        
        // insert numbers from array to set
        for(int num : nums1){
            set1.insert(num);
        }
        for(int num : nums2){
            set2.insert(num);
        }

        // Search numbers from array in set and add to result
        for(int num : set1){
            if(set2.find(num) == set2.end()) result[0].push_back(num);
        }

        for(int num : set2){
            if(set1.find(num) == set1.end()) result[1].push_back(num);
        }
        return result;
    }
};