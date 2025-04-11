class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // Max Heap for score value and their indices
        priority_queue<pair<int, int>> maxHeap;
        vector<string> result(score.size());

        for(int i = 0; i < score.size(); ++i){
            maxHeap.emplace(score[i], i);
        }

        int rank = 1;
        for(int i = 0; i < score.size(); ++i){
            auto itr = maxHeap.top().second; maxHeap.pop();
            if(rank == 1) result[itr] = "Gold Medal";
            else if(rank == 2) result[itr] = "Silver Medal";
            else if(rank == 3) result[itr] = "Bronze Medal";
            else result[itr] = to_string(rank);
            rank++;
        }
        return result;
    }
};