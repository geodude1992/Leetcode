class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        int colCount = 1;

        if(m*n != original.size()) return result;
        vector<int> temp;

        for(int i = 0; i < original.size(); i++){
            temp.push_back(original[i]);
            if(colCount==n){
                result.push_back(temp);
                temp.clear();
                colCount = 0;
            }
            colCount++;
        } 
        return result;
    }
};