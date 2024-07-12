class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(k + 1, vector<int> (n, 0));

        for(int i = 1; i <= k; ++i){
            for(int j = 1; j < n; ++j){
                for(int p = 0; p < j; ++p){
                    dp[i][j] = max(dp[i][j], dp[i - 1][p] + prices[j] - prices[p]);
                }
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            }
        }

        return dp[k][n - 1];
    }
};