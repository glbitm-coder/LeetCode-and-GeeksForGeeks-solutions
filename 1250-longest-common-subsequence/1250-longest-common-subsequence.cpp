class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int> (n2, 0));

        for(int i = 0; i < n2; ++i){
            if(text2[i] == text1[0]){
                dp[0][i] = 1;
            }
            else{
                dp[0][i] = i > 0 ? dp[0][i - 1] : 0;
            }
        }

        for(int i = 0; i < n1; ++i){
            if(text2[0] == text1[i]){
                dp[i][0] = 1;
            }
            else{
                dp[i][0] = i > 0 ? dp[i - 1][0] : 0;
            }
        }

        for(int i = 1; i < n1; ++i){
            for(int j = 1; j < n2; ++j){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};