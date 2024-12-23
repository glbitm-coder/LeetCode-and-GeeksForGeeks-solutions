class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dis(n, INT_MAX);

        dis[0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= nums[i] && i + j < n; ++j ){
                dis[i + j] = min(dis[i + j], dis[i] + 1);
            }
        }
        return dis[n - 1];
    }
};