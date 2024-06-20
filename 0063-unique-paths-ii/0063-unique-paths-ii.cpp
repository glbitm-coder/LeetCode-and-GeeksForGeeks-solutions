class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1){
            return 0;
        }

        for(int i = 1; i < m; ++i){
            if(obstacleGrid[i][0] == 1 || dp[i - 1][0] == -1){
                dp[i][0] = -1; 
            }
        }
        for(int i = 1; i < n; ++i){
            if(obstacleGrid[0][i] == 1 || dp[0][i - 1] == -1){
                dp[0][i] = -1;
            }
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = -1;
                    continue;
                }

                int upper = dp[i - 1][j];
                int left = dp[i][j - 1];
                if(upper == -1 && left == -1){
                    dp[i][j] = -1;
                    continue;
                }
                if(upper == -1){
                    dp[i][j] = left;
                    continue;
                }
                if(left == -1){
                    dp[i][j] = upper;
                    continue;
                }
                dp[i][j] = left + upper;
            }
        }

        return dp[m - 1][n - 1]  == -1 ? 0 : dp[m - 1][n - 1];
    }
};