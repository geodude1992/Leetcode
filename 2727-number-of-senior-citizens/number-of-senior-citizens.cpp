class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;
        for(string &info : details){
            if(((info[11]-'0') * 10) + (info[12]-'0') > 60) seniorCount++;
        }
        return seniorCount;
    }
};