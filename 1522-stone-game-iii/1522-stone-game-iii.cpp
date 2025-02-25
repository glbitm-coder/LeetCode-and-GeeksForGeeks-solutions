class Solution {
public:
    
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n + 1 , -1);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; --i){
            
            dp[i] =  stones[i] - dp[i + 1];

            if(i + 2 <= n)
            dp[i] = max(dp[i], stones[i] + stones[i + 1] - dp[i + 2]);

            if(i + 3 <= n)
            dp[i] = max(dp[i], stones[i] + stones[i + 1] + stones[i + 2] - dp[i + 3]);
        }

        int res = dp[0];
        
        if(res > 0 ) return "Alice";
        else if(res < 0) return "Bob";
        return "Tie";
    }
};