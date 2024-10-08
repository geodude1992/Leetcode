class Solution {
public:
    // T: O(n) - One iteration through the target array 
    // S: O(1) - no use of extra memory
    int minNumberOperations(vector<int>& target) {
        // Initialize noOfOperations with the value of the first element in the target array because the first element needs to be incremented to match the target
        int noOfOperations = target[0];
        // Loop through the target array starting from the second element and compare with previous element
        for(int i = 1; i < target.size(); i++){
            // If the current element is greater than the previous we have an increasing segment
            if(target[i] > target[i-1]){
                // Calculate the difference and add this difference to the noOfOperations
                noOfOperations += (target[i]-target[i-1]);
            }
            // Repeat process for all segments 
        }
        // After iterating through the target array, the value of noOfOperations will represent the minimum number of operations required to transform the initial array into the target array, considering only the increasing segments.
        return noOfOperations;
    }
};