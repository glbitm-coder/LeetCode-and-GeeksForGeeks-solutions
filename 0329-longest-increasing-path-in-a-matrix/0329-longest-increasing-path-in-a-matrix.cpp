class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &dp, int m, int n, vector<vector<int>> &matrix){
        
        if(i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j] && dp[i][j] + 1 > dp[i - 1][j]){
            dp[i - 1][j] = max(dp[i][j] + 1, dp[i - 1][j]);
            dfs(i - 1, j, dp, m, n, matrix);
        }
        if(i + 1 < m && matrix[i][j] < matrix[i + 1][j]  && dp[i][j] + 1 > dp[i + 1][j]){
           dp[i + 1][j] = max(dp[i][j] + 1, dp[i + 1][j]);
            dfs(i + 1, j, dp, m, n, matrix);
        }
        if(j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1] && dp[i][j] + 1 > dp[i][j - 1]){
            dp[i][j - 1] = max(dp[i][j] + 1, dp[i][j - 1]);
            dfs(i, j - 1, dp, m, n, matrix);
        }
        if(j + 1 < n && matrix[i][j] < matrix[i][j + 1] && dp[i][j] + 1 > dp[i][j + 1]){
            dp[i][j + 1] = max(dp[i][j] + 1, dp[i][j + 1]);
            dfs(i, j + 1, dp, m, n, matrix);
        }
        return ;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n , 0));
        vector<pair<int,int>> vp;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                bool isSmall = true;
                if(i - 1 >= 0 && matrix[i][j] > matrix[i - 1][j]){
                    dp[i][j] = 0;
                    isSmall = false;
                }
                if(i + 1 < m && matrix[i][j] > matrix[i + 1][j]){
                    dp[i][j] = 0;
                    isSmall = false;
                }
                if(j - 1 >= 0 && matrix[i][j] > matrix[i][j - 1]){
                    dp[i][j] = 0;
                    isSmall = false;
                }
                if(j + 1 < n && matrix[i][j] > matrix[i][j + 1]){
                    dp[i][j] = 0;
                    isSmall = false;
                }
                if(isSmall) {
                    dp[i][j] = 1;
                    vp.push_back({i,j});
                }
            }
        }
        for(auto it:vp){
            dfs(it.first, it.second, dp, m, n, matrix);
        }
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};