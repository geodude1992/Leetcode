class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, m = matrix.size(), n = matrix[0].size(), right = m * n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid/n][mid%n];

            if(mid_val < target) left = mid + 1;
            else if(mid_val > target) right = mid - 1;
            else return true;
        }
        return false;
    }
};