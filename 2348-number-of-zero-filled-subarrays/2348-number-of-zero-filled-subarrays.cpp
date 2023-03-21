class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int count = 0;
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                ++count;
            }
            else
            {
                if(count > 0)
                {
                    ans += (long long)(((long long)count * ((long long)count + 1)) / 2);
                }
                count = 0;
            }
        }
        if(count != 0)
        {
            ans += (long long)((long long)count * ((long long)count + 1)) / 2;
        }
        return ans;
    }
};