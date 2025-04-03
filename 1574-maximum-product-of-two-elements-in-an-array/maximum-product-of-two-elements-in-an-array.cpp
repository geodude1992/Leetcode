class Solution {
public:
    // Brute force
    /* T: O(n^2)
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        // Iterate through array twice to find largest and second largest number
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                ans = max(ans, (nums[i]-1)*(nums[j]-1));
            }
        }
        return ans;
    }*/

    // Find Largest and save prev largest to secondLargest Solution
    /* T: O(n) - Iterate through the array once
    int maxProduct(vector<int>& nums) {
        int largest = 0;
        int secondLargest = 0;
        
        // Iterate through array 
        for(int &num : nums){
            // If the current number is larger than largest, set largest to current but first save the prev largest to second largest
            if(num > largest){
                secondLargest = largest;
                largest = num;
            }else{
                // Say if our array has two elements and the first is larger than secondLargest will be our curr
                secondLargest = max(secondLargest, num);
            }
        }
        return (largest-1)*(secondLargest-1);
    }*/

    // Priority Queue Solution
    // T: O(n * log n) - iterated nums and log n cost to push to heap
    // S: O(n) - pq
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxHeap;
        for(int &num : nums){
            maxHeap.push(num);
        }
        int l = maxHeap.top(); maxHeap.pop();
        int r = maxHeap.top();
        
        return (l-1)*(r-1);
    }
};