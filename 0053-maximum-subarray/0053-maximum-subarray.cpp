class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, ans = 0;
        for(int i = 0 ; i < nums.size(); ++i){
            ans += nums[i];
            res = max(res, ans);
            if(ans < 0){
                ans = 0;
            }
        }
        return res;
    }
};