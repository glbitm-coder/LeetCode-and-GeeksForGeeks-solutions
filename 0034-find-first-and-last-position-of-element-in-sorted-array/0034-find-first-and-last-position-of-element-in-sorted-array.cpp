class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        vector<int> ans;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                if(mid - 1 >= 0 && nums[mid - 1] == target){
                    right = mid - 1;
                } else {
                    ans.push_back(mid);
                    break;
                }
            } else if(nums[mid] > target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if(ans.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        left = 0;
        right = n - 1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                if(mid + 1 < n && nums[mid + 1] == target){
                    left = mid + 1;
                } else {
                    ans.push_back(mid);
                    break;
                }
            } else if(nums[mid] > target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};