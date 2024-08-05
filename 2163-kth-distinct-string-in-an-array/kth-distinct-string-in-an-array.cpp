class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Map all the string with the number of times each of them occur.
        unordered_map<string, int> umap;
        for(auto &it : arr){
            umap[it]++;
        }
        // Traverse the array once more and decrease the value of k by one, each time you encounter a string with count as 1.
        for(auto &it : arr){
            if(umap[it] == 1 && --k == 0) return it;
        }
        return "";
    }
};