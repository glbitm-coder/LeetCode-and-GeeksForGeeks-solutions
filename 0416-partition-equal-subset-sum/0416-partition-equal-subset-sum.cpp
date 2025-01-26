class Solution {
public:
    bool targetSum(vector<int>& nums, int n, int target){
        int dp[n][target + 1];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= target; ++j){
                if(i == 0){
                    if(j == nums[i]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                if(j == 0) dp[i][j] = 1;
                if(i != 0 && j != 0){
                    if(j < nums[i]) dp[i][j] = dp[i - 1][j];
                    else{
                        dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n - 1][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        return targetSum(nums, n, sum / 2);
    }
};