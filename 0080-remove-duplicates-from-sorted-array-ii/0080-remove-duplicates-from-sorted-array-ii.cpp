class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 2, j = 2; j < nums.size(); ++j){
            if(nums[j] == nums[i - 2]){
                continue;
            }
            else
            {
                nums[i] = nums[j];
                ++i;
                ++count;
            }
        }
        return nums.size() > 2 ? count + 2 : nums.size();
    }
};