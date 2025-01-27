class Solution {
public:
    int targetSum(vector<int>& nums, int n, int target){
        int dp[n + 1][target + 1];
        
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= target; ++j){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
                if(i != 0){
                    if(j < nums[i - 1]) dp[i][j] = dp[i - 1][j];
                    else{
                        dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0,n = nums.size();
        for(int i = 0; i < n; ++i){
            sum += nums[i];
        }
        //s1 + s2 = sum
        //s1 - s2 = target
        //2s1 = sum + target
        //s1 = (sum + target) / 2;
        if((sum + target) % 2 != 0 || (sum + target) < 0){
            return 0;
        }
        target = (sum + target) / 2;
        return targetSum(nums, n, target);
    }
};