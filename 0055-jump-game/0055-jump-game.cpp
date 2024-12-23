class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0, maxD = 0, target = nums.size() - 1;
        for(; start <= maxD && start < nums.size(); ){
            if(start == target){
                return true;
            }
            maxD = max(maxD, start + nums[start]);
            ++start;
        }
        return false;
    }
};