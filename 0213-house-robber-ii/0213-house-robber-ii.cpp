class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size() - 1; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int ans1 = dp[n - 2];
        dp[1] = nums[1];
        dp[2] = max(nums[2], nums[1]);
        for(int i = 3; i < nums.size(); ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
        cout<<ans1<<" "<<dp[n - 1]<<"\n";
        return max(ans1, dp[n - 1]);

    }
};