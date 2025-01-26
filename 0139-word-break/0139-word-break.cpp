class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 0;  j < i; ++j){
                if(dp[j] && us.find(s.substr(j, i - j)) != us.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};