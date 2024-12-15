class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n - 1]){
            return nums[0];
        }

        int start = 0, end = n - 1, mid = 0;
        while(start <= end){
            mid = start + (end - start) / 2;

            if(nums[start] <= nums[end]){
                return nums[start];
            }
            if(nums[mid] >= nums[start]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return -1;
    }
};