class Solution {
public:int perfectSum(vector<int> &arr, int n, int sum)
	{
        // Your code goes here
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        
        for(int i = 0; i <= sum; ++i){
            if(i == arr[0]){
                dp[0][i] = 1;
            }
        }
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= sum; ++j){
                if(arr[i] > j){
                    dp[i][j] = dp[i - 1][j];
                }
                else if(arr[i] == j){
                    dp[i][j] = ((dp[i - 1][j] % mod) + dp[i - 1][0] + 1) % mod;
                }
                else{
                    dp[i][j] = ((dp[i - 1][j] % mod) + (dp[i - 1][j - arr[i]] % mod)) % mod;
                }
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            }
        }
        return dp[n - 1][sum];
	}
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += arr[i];
        }
        if((sum - d) % 2 != 0 || sum - d < 0){
            return 0;
        }
        int target = (sum - d) / 2;
        
        
        int ans = perfectSum(arr, n, target);
        if(sum - d == 0){
            return 1 + ans;
        }
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};