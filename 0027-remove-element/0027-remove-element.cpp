class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i = 0, j = 1; i < nums.size() && j <= nums.size(); ){
            if(nums[i] != val){
                ++i;
                ++j;
            }
            else{
                if(j == nums.size() || nums[j] == val){
                    ++j;
                    continue;
                }
                else{
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    ++i;
                    ++j;
                }
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == val){
                return i;
            }
        }
        return nums.size();
    }
};