class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0], sell = 0, cooldown = 0, prevBuy = 0;
        for(int i = 1; i < prices.size(); ++i){
            prevBuy = buy;
            buy = max(prevBuy, cooldown - prices[i]);
            cooldown = max(cooldown, sell);
            sell = max(sell, prices[i] + prevBuy);
        }
        return max(sell, cooldown);
    }
};