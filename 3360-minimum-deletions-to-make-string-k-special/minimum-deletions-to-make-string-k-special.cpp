class Solution {
public:
    // Minimun Deletions so the resulting string, the frequency diff between ANY two characters is at most k
    int minimumDeletions(string word, int k) {
        // 1. Count character frequencies
        int freq[26] = {0};
        for(char c : word){
            freq[c-'a']++;
        }

        // 2. Extract non-zeros freqs into updated[], track size
        vector<int> freqList;
        freqList.reserve(26);
        for(int f: freq){
            if(f > 0) freqList.push_back(f);
        }

        // 3. Sort only the used portion
        sort(freqList.begin(), freqList.end());

        int n = freqList.size();
        int totalSum = word.size(); // Sum of all freqs
        int removedLeft = 0;        // Sum of freqs fullly deleted on left    
        int inWindowSum = 0;        // Sum of freqs inside [i..j)
        int best = INT_MAX;         // Best answer so far
        int r = 0;                  // right pointer for window

        // 4. Slide the window start i across all freqs
        for(int i = 0; i < n; ++i){
            int base = freqList[i];
            int limit = base + k;

            while(r < n && freqList[r] <= limit)
                inWindowSum += freqList[r++];

            int rightCount = n - r;
            int rightSum = totalSum - inWindowSum;
            int delRight = rightSum - rightCount * limit;

            best = min(best, removedLeft + delRight);

            totalSum -= freqList[i];
            removedLeft += freqList[i];
            inWindowSum -= freqList[i];
        }
        return best;
    }
};