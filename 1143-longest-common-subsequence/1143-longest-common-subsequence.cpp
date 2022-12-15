class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = (int)text1.size();
        int n2 = (int)text2.size();
        
        vector<vector<int>> dp(n1, vector<int> (n2, 0));
        if(text2[n2 - 1] == text1[n1 - 1])
        {
            dp[n1 - 1][n2 - 1] = 1;
        }
        for(int i = n1 - 2; i >= 0 ; --i)
        {
            if(text2[n2 - 1] == text1[i])
            {
                dp[i][n2 - 1] = 1;
            }
            else
            {
                dp[i][n2 - 1] = dp[i + 1][n2 - 1];
            }
        }
        for(int i = n2 - 2; i >= 0; --i)
        {
            if(text2[i] == text1[n1 - 1])
            {
                dp[n1 - 1][i] = 1;
            }
            else
            {
                dp[n1 - 1][i] = dp[n1 - 1][i + 1];
            }
        }
        for(int i = n1 - 2; i >= 0; --i)
        {
            for(int j = n2 - 2; j >= 0; --j)
            {
                if(text1[i] == text2[j])
                {
                     dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        
        return dp[0][0];
    }
};