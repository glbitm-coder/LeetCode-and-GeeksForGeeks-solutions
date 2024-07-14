class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n);
        dp[0] = 1;
       
        for(int i = 1; i < n; ++i){
            int ans = 0, result = 0;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    ans = dp[j];
                }
                result = max(ans, result);
            }
            dp[i] = result + 1;
          
        }
        return *max_element(dp.begin(), dp.end());
    }
};