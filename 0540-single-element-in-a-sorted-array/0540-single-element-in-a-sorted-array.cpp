class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size() - 1;
        int mid = 0;
        if(n == 0) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n] != nums[n - 1]) return nums[n];
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(mid > 0 && mid < n && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else if(mid % 2 == 0)
            {
                if(mid > 0 && nums[mid] == nums[mid - 1])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if(mid % 2 != 0)
            {
                if(mid > 0 && nums[mid] == nums[mid - 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};