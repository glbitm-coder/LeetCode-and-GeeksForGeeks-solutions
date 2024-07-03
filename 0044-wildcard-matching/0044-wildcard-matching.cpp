class Solution {
public:

    bool check(int curr_s, string &s, int curr_p, string &p, int n, int m, vector<vector<long long int>> &dp){
        
        if(curr_s == n && curr_p == m){
            return true;
        }
        else if(curr_s == n && curr_p < m){
            for(int i = curr_p; i < m; ++i){
                if(p[i] != '*'){
                    return false;
                }
            }
            return  true;
        }
        else if(curr_s < n && curr_p == m){
            return false;
        }
    
        if(dp[curr_s][curr_p] != -1){
            return dp[curr_s][curr_p];
        }
        if(s[curr_s] == p[curr_p] || p[curr_p] == '?'){
            dp[curr_s][curr_p] = check(curr_s + 1, s, curr_p + 1, p, n , m, dp);
        }
        else if(p[curr_p] == '*'){
            dp[curr_s][curr_p] = (check(curr_s + 1, s, curr_p, p, n , m, dp) || check(curr_s, s, curr_p + 1, p, n , m, dp));
        }
        else{
            dp[curr_s][curr_p] = false;
        }

        return dp[curr_s][curr_p];
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        //vector<vector<long long int>> dp(n + 1, vector<long long int> (m + 1, -1));
        // return check(0, s, 0, p, n, m, dp);
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n; ++i){
            dp[i][0] = false;
        }

        for(int i = 1; i <= m; ++i){
            bool flag = true;
            for(int j = 1; j <= i; ++j){
                if(p[j - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag;
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};