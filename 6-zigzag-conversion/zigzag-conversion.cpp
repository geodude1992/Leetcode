class Solution {
public:
    string convert(string s, int numRows) {
        string result;

        // Base Case:
        if(numRows <= 1) return s;

        // Temp Matrix
        vector<string> tVec(numRows, "");

        int j = 0, dir = -1;

        for(int i = 0; i < s.length(); i++){
            if(j == numRows - 1 || j == 0) dir *= (-1);
            // append char to appropriate row/col
            tVec[j] += s[i];
            
            // increment or decrement row
            if(dir == 1) j++;
            else j--;
        }      
        // Convert Matrix to String
        for(auto &it : tVec) result += it;
        return result;
    }
};