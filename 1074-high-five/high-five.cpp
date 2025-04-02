#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // Table of students with their scores listed greatest to lowest
        map<int, priority_queue<int>> table;    // Using map instead of unordered since we are returning ID's in ascending order
        vector<vector<int>> topFiveAvg;

        // 1. Populate Table
        for(auto &x : items)
            table[x[0]].push(x[1]);

        // 2. Iterate through each student ID in table
        for(auto &g : table){
            int sum = 0;
            // 3. Add students grade into the sum
            for(int i = 0; i < 5; ++i){
                sum += g.second.top(); g.second.pop();
            }
            // 4. Calculate Average for each student
            topFiveAvg.push_back({g.first, sum / 5});
        }
        return topFiveAvg;
    }
};