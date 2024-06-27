class Solution {
public:
    bool isSubsetSum(vector<int> &arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= sum; ++j){
                if(arr[i] == j){
                    dp[i][j] = 1;
                }
                else if(i - 1 >= 0 && dp[i - 1][j] == 1){
                    dp[i][j] = 1;
                }
                else if(i - 1 >= 0 && j - arr[i] >= 0 && dp[i - 1][j - arr[i]] == 1){
                    dp[i][j] = 1;
                }
            }
        }
        if(dp[n - 1][sum] == 1){
            return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
        }

        if(sum % 2 != 0)
            return false;

        return isSubsetSum(nums, sum / 2);
    }
};