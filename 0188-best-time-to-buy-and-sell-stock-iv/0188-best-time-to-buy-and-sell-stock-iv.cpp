class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(k + 1, vector<int> (n, 0));

        for(int i = 1; i <= k; ++i){
            int val = INT_MIN;
            for(int j = 1; j < n; ++j){
                val = max(val, dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(val + prices[j], dp[i][j - 1]);
            }
        }
        return dp[k][n - 1];
    }
};