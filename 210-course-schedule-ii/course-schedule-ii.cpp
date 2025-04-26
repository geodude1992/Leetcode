class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Initializing a 2D graph
        vector<vector<int>> graph(numCourses);
        vector<int> result, indegree(numCourses);   // indegree keeps track of visited nodes

        // Indgree
        for(auto& prereq : prerequisites){
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        // dfs call
        function<void(int)> dfs = [&](int current){
            // Add current course into the result
            result.push_back(current);
            // Making sure that the current course that we added is marked as visited
            indegree[current] = -1;

            // if any next course has a indegree of 0
            for(auto nextCourse : graph[current]){
                if(--indegree[nextCourse] == 0) dfs(nextCourse);
            }
        };

        // If the indegree becomes 0 of a course then again add then into DFS
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) dfs(i);
        }

        // In the end return 
        if(result.size() == numCourses) return result;
        result.clear();
        return result;
    }
};