class Solution {
/*
    Greedy Solution but MATHY

    maxm-1 == Number of cycles
    n+1 == Number of slots per cycle
    maxcount == Number of tasks having maximum frequency, fmax.
*/
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0}; // Constant amount of space regardless of the input size
        int maxm = 1; // max freq == maxm
        // Calculate Frequencies
        for(char &ch: tasks){
            freq[ch-'A']++;
            maxm = max(maxm, freq[ch-'A']);
        }
        // TEST PRINT ALL FREQ
        /*for (int i = 0; i < 26; ++i) {
            cout << "Position " << (char)('A' + i) << ": " << freq[i] << endl;
        }*/
        
        int maxcount = 0;
        // Count the Maximum Frequency
        for(int &x: freq)
            if(maxm == x)
                maxcount++;
        return max((int)tasks.size(), ((n+1) * (maxm-1) + maxcount)); //typecasting (size_t) into (int).
    }
};