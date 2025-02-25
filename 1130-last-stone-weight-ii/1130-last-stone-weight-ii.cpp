class Solution {
public:
//let say array be [a,b,c,d]
//answer = (a+b)-(c+d) OR
//answer = a-(b+c+d) Or
//answer = (d+b)-(a+c) and so on.. any combination could be possible
//notice that in general I can say that
//answer = S1-S2
//where S1 is sum of some of the numbers and S2 is sum of rest of numbers
//also note that S1+S2 = SUM (sum of all numbers)
//S1 >= S2 beacuse negative answer is not possible
//now we have to minimise answer
//answer = SUM - 2*S2 (Just substituting S1 by SUM-S2)
//To minimise answer S2 has to be maximum
//Now, max value of S2 is SUM/2 (bigger than this and answer would be negative which is not possible)
//so the question reduces to find closest sum (sum of numbers) to (SUM/2)
//now this could be understood as subset sum problem or 0/1 knapsack problem
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0, half = 0, n = stones.size();
        for(int i = 0; i < n; ++i){
            total += stones[i];
        }

        half = total / 2;
        vector<vector<int>> dp(n + 1, vector<int> (half + 1, 0));

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= half; ++j){
                if(stones[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }
        return total - 2 * dp[n][half];
    }
};