class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<long double>> dp(n1, vector<long double> (n2, 0));

        for(int i = 0; i < n1; ++i){
            dp[i][0] = i == 0 ? (s[i] == t[0] ? 1 : 0) : ( s[i] == t[0] ? dp[i - 1][0] + 1 : dp[i - 1][0]);
        }

        for(int i = 1; i < n1; ++i){
            for(int j = 1; j < n2; ++j){
                if(s[i] == t[j]){
                    dp[i][j] = (long double)dp[i - 1][j] + (long double)dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n1 - 1][n2 - 1];
    }
};