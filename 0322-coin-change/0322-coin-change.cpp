class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount + 1];
        
    
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            dp[i] = INT_MAX;
            for(int j = 0; j < n; ++j){
                if(i >= coins[j]){
                    if(dp[i - coins[j]] != INT_MAX){
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
        }
        return dp[amount] == INT_MAX  ? -1 : dp[amount];
    }
};