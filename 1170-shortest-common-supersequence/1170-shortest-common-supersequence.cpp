class Solution {
public:
int longestCommonSubsequence(string text1, string text2, vector<vector<int>> &dp) {
        int n1 = text1.size();
        int n2 = text2.size();

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
     
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
	    int n2 = str2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, 0));
        int length = longestCommonSubsequence(str1, str2, dp);
        
        int i = n1 - 1;
        int j = n2 - 1;
        string ans = "";
        while(i >= 0 && j >= 0){
            // cout<<i<<" "<<j<<" "<<ans<<"\n";
            if(dp[i][j] == 0){
                break;
            }
            if(str1[i] == str2[j]){
                ans += str1[i];
                --i;
                --j;
            }
            else{
                if(i - 1 >= 0 && j - 1 >= 0){
                    if(i - 1 >= 0 && dp[i - 1][j] > dp[i][j - 1]){
                        ans += str1[i];
                        --i;
                    }
                    else{
                        ans += str2[j];
                        --j;
                    }
                }
                else{
                    if(j == 0 && i - 1 >= 0 && dp[i - 1][j] == 1){
                        ans += str1[i];
                        --i;
                    }
                    else if(i == 0 && j >= 0 && dp[i][j - 1] == 1){
                        ans += str2[j];
                        --j;
                    }
                }
            }
        }
        while(i >= 0){
            ans += str1[i];
            --i;
        }
        while(j >= 0){
            ans += str2[j];
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};