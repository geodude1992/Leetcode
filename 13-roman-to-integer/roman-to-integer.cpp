class Solution {
public:
    int romanToInt(string s) {
        int intval = 0;
        unordered_map<char, int> hmap{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for(int i = 0; i<s.size(); ++i){
            // Case for the 1st Roman Numeral is smaller than the next
            if(hmap[s[i]] < hmap[s[i + 1]]){
                intval -= hmap[s[i]];
            }else{
                intval += hmap[s[i]];
            }
        }
        return intval;
    }
};