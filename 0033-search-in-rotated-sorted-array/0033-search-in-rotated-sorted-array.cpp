class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid = 0;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(target == nums[start]){
                return start;
            }
            if(target == nums[end]){
                return end;
            }
            if(target == nums[mid]){
                return mid;
            }
            if(nums[start] > nums[mid]){
                if(target > nums[start] || target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{
                if(target > nums[start] && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
};