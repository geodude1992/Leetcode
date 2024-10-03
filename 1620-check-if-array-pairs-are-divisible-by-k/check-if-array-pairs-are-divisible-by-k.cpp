class Solution {
public:
    // Hashing - to form a pair pick int p1 from arr and calculate its value modulo k (mod) and p2 = k - mod
    // (ai + aj) % k = 0
    // T: O()
    // S: O()
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;
        
        for(int i = 0; i < arr.size(); i++){
            remainderCount[(arr[i] % k + k) % k]++;
        }

        for(int i = 0; i < arr.size(); i++){
            int remainder = (i % k + k) % k;
        
            // 
            if(remainder == 0){
                if(remainderCount[remainder] % 2 == 1) return false;
            }
            else if(remainderCount[remainder] != remainderCount[k - remainder]) return false;
        }
        return true;
    }
};