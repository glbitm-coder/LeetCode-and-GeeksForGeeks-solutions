class Solution {
public:
    bool isInter(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>> &dp){
        // cout<<i<<" "<<j<<" "<<k<<"\n";
        if(i == s1.size() && j == s2.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(i == s1.size()){
            if(s2[j] == s3[k])
            {
                dp[i][j] = isInter(i, j + 1, k + 1, s1, s2, s3, dp);
                return dp[i][j];
            }
        }
        if(j == s2.size()){
            if(s1[i] == s3[k]){
                dp[i][j] = isInter(i + 1, j, k + 1, s1, s2, s3, dp);
                return dp[i][j];
            }
        }
        if(s1[i] != s2[j]){
            if(s1[i] == s3[k]){
                dp[i][j] = isInter(i + 1, j, k + 1, s1, s2, s3, dp);
                return dp[i][j];
            }
            else if(s2[j] == s3[k]){
                dp[i][j] = isInter(i, j + 1, k + 1, s1, s2, s3, dp);
                return dp[i][j];
            }
            else{
                dp[i][j] = false;
                return dp[i][j];
            }
        }
        else{
            if(s1[i] == s3[k]){
                dp[i][j] = isInter(i, j + 1, k + 1, s1, s2, s3, dp) || isInter(i + 1, j, k + 1, s1, s2, s3, dp);
                return dp[i][j];
            }
            else{
                dp[i][j] = false;
                return false;
            }
        }
        dp[i][j] = false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size() + 1, -1));
        if(s1.size() + s2.size() != s3.size()) return false;
        return isInter(0, 0, 0, s1, s2, s3, dp);
    }
};