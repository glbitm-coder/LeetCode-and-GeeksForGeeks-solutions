class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int temp;
        for(int i = 0, j = n - 1; i < j; ){
            if(nums[i]% 2 == 0){
                ++i;
            } else {
                if(nums[j] % 2 == 0){
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    ++i;
                    --j;
                } else {
                    --j;
                }
            }
        }
        return nums;
    }
};