class Solution {
    // Bruteforce - iterate through every pair, 4 for loops. T:O(n^4) S:O(1)
public:
    // Hashmap Solution (Optimal)
    // T: O(n^2) - O(n^2) Iterate through different (A, B) pairs & search through all possible (C, D) points (hashmap & set O(1))
    // S: O(n) - Total number of points
    int minAreaRect(vector<vector<int>>& points) {
        // Hashmap(key: int of x coordinates, value: Set of y coordinates having same x coordinates)
        unordered_map<int, unordered_set<int>> x_map_y;
        
        // Iterate through every single point & store the coordinates in map.
        for(auto& single_point : points){
            // Insert y cooridinate into Value (HashSet) corresponding to Key
            x_map_y[single_point[0]].insert(single_point[1]);
            // Explanation : 
			//		single_point => refering to a single point [x,y] in vector
			//		x-coordinate of a single point => single_point[0]
			//		y-coordinate of a single point => single_point[1]

			//		Key => x coordinate of a point 
			//			=> single_point[0]

			//		Value => HashSet of y coordinates 
			//			=> hashmap[Key]
			//			=> hashmap[x-coordinate of a single point]
			//			=> hashmap[single_point[0]]

			//		Insert y coordinate into corresponding Value (HashSet)
			//			=> Value.insert(y-coordinate of a single point)
			//			=> hashmap[Key].insert(y-coordinate of a single point)
			//			=> hashmap[x-coordinate of a single point].insert(y-coordinate of a single point)
			//			=> hashmap[single_point[0]].insert(single_point[1])
        }
        // Variable to store the minimum area
        int minimum_area = INT_MAX;

        // Iterate corresponding to differenct A points
        for(int i = 0; i < points.size(); i++){
            // Iterate corresponding to different B points
            for(int j = i + 1; j < points.size(); j++){
                int x1 = points[i][0], y1 = points[i][1];   // Coordinates of Point A
                int x2 = points[j][0], y2 = points[j][1];   // Coordinates of Point B

                // Point A & B must form a diagonal of the rectangle
                if(x1 != x2 && y1 != y2){
                    if(x_map_y[x1].find(y2) != x_map_y[x1].end() && // Check if D exist in hashmap
                        x_map_y[x2].find(y1) != x_map_y[x2].end()){ // Check if C exist in hashmap
                    // Explanation : 
					//		Check existence of y2 in Value (HashSet) corresponding to x1 Key
					//			=> Value.find(y-coordinate of point B)
					//			=> hashmap[Key].find(y-coordinate of point B)
					//			=> hashmap[x-coordinate of point A].find(y-coordinate of point B)
					//			=> hashmap[x1].find(y2) => Checks if point D exists in hashmap 
					//		Check existence of y1 in Value (HashSet) corresponding to x2 Key
					//			=> Value.find(y-coordinate of point A)
					//			=> hashmap[Key].find(y-coordinate of point A)
					//			=> hashmap[x-coordinate of point B].find(y-coordinate of point A)
					//			=> hashmap[x2].find(y1) => Checks if point C exists in hashmap 

                    // Store minimum area possible
                    minimum_area = min(minimum_area, abs(x1-x2) * abs(y1-y2));
                    }
                }
            }
        }
        // Return 0 if no rectangle exists
        return minimum_area != INT_MAX ? minimum_area : 0;
    }
};