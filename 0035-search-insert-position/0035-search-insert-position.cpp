class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto a = lower_bound(nums.begin(), nums.end(), target);
        return a - nums.begin();
    }
};