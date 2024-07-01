class Solution {
public:
int longestPalindromeSubseq(string s) {
        int n = s.size();
    
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int gap = 0; gap < n; ++gap){
            for(int i = 0, j = i + gap; j < n; ++i, ++j){
                if(gap == 0){
                    dp[i][j] = 1;
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                    else{
                        dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }

    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};