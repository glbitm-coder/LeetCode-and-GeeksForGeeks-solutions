class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        unsigned long long dp[n][amount + 1];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= amount; ++j){
                if(i == 0 || j == 0){
                    if(j % coins[i] == 0) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else{
                    if(j < coins[i]) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
            }
        }
        return dp[n - 1][amount];
    }
};