class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i){
            int val = 1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    val = max(val, dp[j] + 1);
                }
            }
            dp[i] = val;
            ans = max(ans, dp[i]);
        }

        return max(1, ans);
    }
};