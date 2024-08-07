class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (3, 0));

        dp[0][0] = -prices[0];

        for(int i = 1; i < n; ++i){
            
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);

            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);

            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);

        }

        int ans = 0;
        for(int i = 0; i < 3; ++i){
            ans = max(ans, dp[n - 1][i]);
        }

        return ans;
    }
};