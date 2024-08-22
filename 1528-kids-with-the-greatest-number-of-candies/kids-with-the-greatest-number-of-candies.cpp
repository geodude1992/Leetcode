class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max_candy = 0;
        for(int c : candies){
            max_candy = max(c, max_candy);
        }

        for(int i = 0; i <= candies.size() - 1; i++){
            if(candies[i] + extraCandies >= max_candy) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};