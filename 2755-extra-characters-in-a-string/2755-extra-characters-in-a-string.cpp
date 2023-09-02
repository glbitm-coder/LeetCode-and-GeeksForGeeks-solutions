class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        for (auto word : dictionary)
        {
            dict.insert(word);
        }

        int n = s.length();

        vector<int> dp(n + 1);
        
        for (int p = 1; p <= n; p++) {
            dp[p] = dp[p - 1] + 1;

            for (int q = p; q >= 1; q--) {
                string substring = s.substr(q - 1, p - q + 1);

                if (dict.count(substring)) {
                    dp[p] = min(dp[p], dp[q - 1]);
                }
            }
        }

        return dp[n];
        
    }
};