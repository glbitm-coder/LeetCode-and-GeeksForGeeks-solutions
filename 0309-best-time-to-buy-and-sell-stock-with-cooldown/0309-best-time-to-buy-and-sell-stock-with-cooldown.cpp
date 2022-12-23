class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size() == 0) return 0;
        int hold = -prices[0],cash=0,cool=0;
        for(int i=1;i<prices.size();i++){
            int prev_hold = hold;
            hold = max(hold,cool-prices[i]);
            cool = max(cool,cash);
            cash = max(cash,prev_hold+prices[i]);
        }
        return cash;
    }
};