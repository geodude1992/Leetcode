class Solution {
public:
    // Sliding Window Heap(Priority Queue) Solution
    // T: O(n klogk) - 
    // S: O(n + k) - array length n and sub array k
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;

        // Initialize unordered map to count the frequency of elements in the current subarray of length k.
        unordered_map<int, int> freq;
        for(int i = 0; i < k; i++){
            // Store elements from nums array and update frequency count
            freq[nums[i]]++;
        }

        // Calculate xsum for first window
        result.push_back(calculateXSum(freq, x));

        // Sliding Windown
        for(int i = 1;  i <= nums.size() - k; i++){
            // Remove the element going out of out window by decrementing its count in the map
            freq[nums[i - 1]]--;
            if(freq[nums[i - 1]] == 0){
                freq.erase(nums[i - 1]);
            }

            // Add the new element coming into the window
            freq[nums[i + k - 1]]++;

            // Calculate x-sum for the current window
            result.push_back(calculateXSum(freq, x));
        }
        return result;
    }

    // For the first window, determine the x-sum using the most frequent elements. 
    // If frequencies are tied, choose the larger value.
    // Use a max heap for efficient retrieval of the top x elements. 
    int calculateXSum(const unordered_map<int, int>& freq, int x){
        int sum = 0;

        // Priority Queue(max heap) to get top x elements
        priority_queue<pair<int, int>> pq;  // Pair(frequency, value)

        // Iterate through frequency map and push pair(frequency, value) into the priority queue
        for(const auto& entry : freq){
            pq.push({entry.second, entry.first});
        }

        // Calculate X Sum
        for(int i = 0; i < x && !pq.empty(); i++){
            sum += pq.top().second * pq.top().first; // sum = value * frequency
            pq.pop();
            
        }
        return sum;
    }
};