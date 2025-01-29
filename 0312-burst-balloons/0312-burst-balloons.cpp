class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> pq;
        pq.push_back(1);
        for(auto it:nums) pq.push_back(it);
        pq.push_back(1);
        int n = pq.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int gap = 2; gap <= n - 1; ++gap){
            for(int i = 0, j = i + gap; i < n && j < n; ++i, ++j){
                for(int k = i + 1; k < j; ++k){
                    dp[i][j] = max(dp[i][j], (pq[i] * pq[k] * pq[j]) + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};