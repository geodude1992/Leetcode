class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxPro = 0;

        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int currentProfit = prices[r] - prices[l];
                maxPro = std::max(maxPro, currentProfit);
            }else{
                l=r;
            }
            r++;
        }
        return maxPro;
    }
};