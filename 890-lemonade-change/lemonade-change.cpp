class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changeOf5s = 0, changeOf10s = 0;
        for(int i = 0; i <= bills.size() - 1; i++){
            if(bills[i] == 5) changeOf5s++;
            else if(bills[i] == 10 && changeOf5s > 0) {
                changeOf5s--;
                changeOf10s++;
            }
            else if(bills[i] == 20 && changeOf5s > 0 && changeOf10s > 0){
                changeOf5s--;
                changeOf10s--;
            }else if(bills[i] == 20 && changeOf5s >= 3 && changeOf10s == 0){
                changeOf5s-=3;
            }

            else return false;
        }
        return true;
    }
};