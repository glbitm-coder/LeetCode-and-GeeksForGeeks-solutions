class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = (int)nums.size();
        vector<long int> prefix_sum_average(n);
        vector<long int> suffix_sum_average(n);
        
        prefix_sum_average[0] = nums[0];
        //Storing prefix sum for each index;
        for(int i = 1; i < n; ++i)
        {
            prefix_sum_average[i] = prefix_sum_average[i - 1] + nums[i];
        }
        
        //Storing prefix sum avereage for each index;
        for(int i = 1; i < n; ++i)
        {
            prefix_sum_average[i] = prefix_sum_average[i] / (i + 1);
        }
        
        suffix_sum_average[n -1] = 0;
        //Storing suffix sum for each index;
        for(int i = n - 2; i >= 0; --i)
        {
            suffix_sum_average[i] = suffix_sum_average[i + 1] + nums[i + 1];
        }
        
        //Storing suffix sum average for each index;
        for(int i = n - 2; i >= 0; --i)
        {
            suffix_sum_average[i] = suffix_sum_average[i] / (n - i - 1);
        }
        
        //Find absolute value
        for(int i = 0; i < n; ++i)
        {
            nums[i] = abs(prefix_sum_average[i] - suffix_sum_average[i]);
        }
        
        //Find minimum average difference
        int min = *min_element(nums.begin(), nums.end());
        
        //Find index having minimum average difference
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == min)
                return i;
        }
        return -1;
    }
};