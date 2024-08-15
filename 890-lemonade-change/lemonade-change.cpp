class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // keep count of $5 and $10 bills since both can be used to give back change
        int changeOf5s = 0, changeOf10s = 0;
        for(int i = 0; i <= bills.size() - 1; i++){
            if(bills[i] == 5) changeOf5s++;
            // if customer pays with a $10 give back a $5 and 
            else if(bills[i] == 10 && changeOf5s > 0) {
                changeOf5s--;
                changeOf10s++;
            }
            // 2 cases if customer pays with a $20 bill. we give back a $5 and $10 or three $5
            else if(bills[i] == 20 && changeOf5s > 0 && changeOf10s > 0){
                changeOf5s--;
                changeOf10s--;
            }else if(bills[i] == 20 && changeOf5s >= 3 && changeOf10s == 0){
                changeOf5s -= 3;
            }

            else return false;
        }
        return true;
    }
};