class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int count = 0;
        string ans;
        int max= 0;
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int gap = 0; gap < n; ++gap){
            for(int i = 0, j  = gap; j < n; ++i, ++j){
                if(gap == 0){
                    dp[i][j] = true;
                }
                else if(gap == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(s[i] == s[j] and dp[i + 1][j - 1] == true){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j] and (j - i + 1) > max){
                    ans =s.substr(i, j - i + 1);
                    max = j - i + 1;
                    
                }
            }
        }
        return ans;
    }
};