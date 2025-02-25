class Solution {
public:
    vector<int> dp;
    int solve(int curr, vector<int> &stones, int n){
        if(curr >= n) return 0;
        if(dp[curr] != -1)
            return dp[curr];
        
        int res = stones[curr] - solve(curr + 1, stones, n);
        
        if(curr + 1 < n )
            res = max(res, stones[curr] + stones[curr + 1] - solve(curr + 2, stones, n));

        if(curr + 2 < n)
            res = max(res, stones[curr] + stones[curr + 1] + stones[curr + 2] - solve(curr + 3, stones, n));

        return dp[curr] = res;

    }
    string stoneGameIII(vector<int>& stones) {
        dp.resize(stones.size() + 1 , -1);
        int res = solve(0, stones, stones.size());

        
        if(res > 0 ) return "Alice";
        else if(res < 0) return "Bob";
        return "Tie";
    }
};