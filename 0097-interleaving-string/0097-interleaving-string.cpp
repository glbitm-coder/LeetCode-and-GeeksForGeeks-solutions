class Solution {
public:
    bool isInter(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>> &dp){
        // cout<<i<<" "<<j<<" "<<k<<"\n";
        if(i == s1.size() && j == s2.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = i < s1.size() && s1[i] == s3[k] && isInter(i + 1, j, k + 1, s1, s2, s3, dp) || 
                    j < s2.size() && s2[j] == s3[k] && isInter(i, j + 1, k + 1, s1, s2, s3, dp);
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size() + 1, -1));
        if(s1.size() + s2.size() != s3.size()) return false;
        return isInter(0, 0, 0, s1, s2, s3, dp);
    }
};