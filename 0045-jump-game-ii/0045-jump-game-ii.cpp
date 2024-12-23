class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), ans = 0, far = 0, end = 0;
        for(int i = 0; i < n - 1; ++i){
            far = max(far, i + nums[i]);
            if(far >= n - 1){
                ++ans;
                return ans;
            }
            if(i == end){
                ++ans;
                end = far;
            }
        }
        return ans;
    }
};