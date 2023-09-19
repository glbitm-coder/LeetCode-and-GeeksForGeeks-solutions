class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int p;
        for(int i = 0; i < n; ++i){
            p = abs(nums[i]);

            if(nums[p] < 0) return p;

            nums[p] = - nums[p];
        }
        return 0;
    }
};