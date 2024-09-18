class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        /*unordered_set<string> common;
        vector<string> result;
        string word = "";

        for(char ch : s1){
            if(s1.at(i) != ' ') temp += s1[i];
            else if(s1.at(i) == ' '){
                common.insert(temp);
                temp="";
            }
        }
        common.insert(temp);
        temp="";
        for(int i = 0; i < s2.length(); i++){
            if(s2.at(i) != ' ') temp += s2[i];
            else if(s1.at(i) == ' '){
                common.insert(temp);
                temp="";
            }
        }
        for(string word : common){
            result.push_back(word);
        }
        return result;*/
        unordered_map<string, int> common;
        vector<string> result;
        string word = "";

        for(char ch : s1){
            if(ch == ' '){
                common[word]++;
                word = "";
            }else{
                word += ch;
            }
        }
        // Adds the last word in s1 after the loop above terminated and resets word temp variable
        common[word]++;
        word = "";

        for(char ch : s2){
            if(ch == ' '){
                common[word]++;
                word = "";
            }else{
                word += ch;
            }
        }
        // Adds the last word in s2 after the loop above terminated. no need to reset temp variable
        common[word]++;
        // itr.first: The key of the unordered_map. 
        // itr.second: The value associated with that key.
        for(auto itr : common){
            if(itr.second == 1) result.push_back(itr.first);    // Add the word(Key) that occurs only once(value=1)
        }
        return result;
    }
};