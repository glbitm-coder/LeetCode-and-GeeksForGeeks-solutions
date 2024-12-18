class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i = 1, j = 1; j < nums.size(); ++j){
            if(nums[j] == nums[j - 1]){
                continue;
            }
            else{
                nums[i] = nums[j];
                ++count;
                ++i;
            }
        }
        return count + 1;
    }
};