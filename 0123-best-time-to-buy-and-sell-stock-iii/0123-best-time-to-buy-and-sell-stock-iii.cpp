class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixProfit(n, 0);

        int minValue = prices[0],  maxValue = prices[n - 1], ans = 0;;
        for(int i = 1; i < n; ++i){
            prefixProfit[i] = max(prefixProfit[i - 1], prices[i] - minValue);

            minValue = min(minValue, prices[i]); 
        }

        vector<int> suffixProfit(n, 0);
        for(int i = n - 2; i >= 0; --i){
            suffixProfit[i] = max(suffixProfit[i + 1], maxValue - prices[i]);

            maxValue = max(maxValue, prices[i]);

            ans = max(ans, prefixProfit[i] + suffixProfit[i]);
        }

        return max(max(ans, prefixProfit[n - 1]), suffixProfit[0]); 




    }
};