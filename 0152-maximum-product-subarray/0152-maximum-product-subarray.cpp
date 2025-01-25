class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minNumber = 1,maxNumber = 1, ans = nums[0];
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                minNumber = 1;
                maxNumber = 1;
                ans = max(ans, nums[i]);
            }
            else if(nums[i] < 0){
                int temp = minNumber;
                minNumber = maxNumber;
                maxNumber = temp;
            }
            minNumber = min(minNumber * nums[i], nums[i]);
            maxNumber = max(maxNumber * nums[i], nums[i]);
            ans = max(ans, maxNumber);
        }
        return ans;
    }
};