class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        int current_sum = 0;
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1)
        {
            return nums[0];
        }
        int ans = nums[0];
        for(int i = 0; i < n; ++i)
        {
            if(current_sum < 0){
                current_sum = nums[i];
            }
            else{
                current_sum += nums[i];
            }
            ans = max(ans, current_sum);
        }
        return ans;
    }
};