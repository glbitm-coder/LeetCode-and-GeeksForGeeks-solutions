class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;
        for(int i = 0; i < prices.size(); ++i){
            minPrice = min(prices[i], minPrice);
            ans = max(ans,prices[i] - minPrice);
        }

        return ans;
    }
};