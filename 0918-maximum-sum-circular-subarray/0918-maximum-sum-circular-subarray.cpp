class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int max_kadane_sum = nums[0];
        int min_subarray_sum = 0;
        int current_sum = 0;
        int count = 0;
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] < 0)
            {
                count++;
            }
           
            if( current_sum < 0)
            {
                current_sum = nums[i];
            }
            else
            {
                current_sum += nums[i];
            }
            max_kadane_sum = max(max_kadane_sum, current_sum);
        }
        
        if(count == n) return *max_element(nums.begin(), nums.end());
        
        current_sum = 0;
        for(int i = 0; i < n; ++i)
        {
            
            sum += nums[i];
            nums[i] = 0-nums[i];
           
            if( current_sum < 0)
            {
                current_sum = nums[i];
            }
            else
            {
                current_sum += nums[i];
            }
            min_subarray_sum = max(min_subarray_sum, current_sum);
        }
        
        return max(max_kadane_sum,sum + min_subarray_sum);
    }
};