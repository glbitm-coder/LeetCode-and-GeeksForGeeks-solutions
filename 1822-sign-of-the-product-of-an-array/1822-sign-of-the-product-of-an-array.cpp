class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int prod = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) prod = prod * -1;
        }
        return prod;
    }
};