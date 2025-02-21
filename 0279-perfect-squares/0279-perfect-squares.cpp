class Solution {
public:
    bool isSq(int n){
        int num = sqrt(n);
        if(num * num == n) return true;
        return false;
    }
    int numSquares(int n) {
        vector<unsigned int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        if(isSq(n)) return 1;
        for(int i = 1; i <= n; ++i){
            if(isSq(i)){
                dp[i] = 1;
                continue;
            }
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
                
            }
        }
        return dp[n];
    }
};