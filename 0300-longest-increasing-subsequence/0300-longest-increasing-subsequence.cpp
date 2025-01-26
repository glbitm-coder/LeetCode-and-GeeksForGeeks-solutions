class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxN = 1;
        int dp[n];
        int ans = 1;
        for(int i = 0; i < n; ++i){
            dp[i] = 1;
        }
        for(int i = 1; i < n; ++i){
            maxN = 1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    maxN = max(maxN, dp[j] + 1);
                }
            }
            dp[i] = maxN;
            ans = max(ans, maxN);
       }
       return ans;
    }
};