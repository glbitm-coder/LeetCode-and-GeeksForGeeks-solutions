class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        bool isIncrease = false;
        bool isDecrease = false;

        for(int i = 1; i < n; ++i){
          if(nums[i] > nums[0]){
            isIncrease = true;
            break;
          } else if(nums[i] < nums[0]){
            isDecrease = true;
            break;
          }
        }

        for(int i = 0; i < n - 1; ++i){
          if(nums[i] == nums[i + 1]){
            continue;
          } else if(nums[i] < nums[i + 1]){
            if(isDecrease) return false;
            else if(isIncrease) continue;
          } else {
          if(isIncrease) return false;
          else if(isDecrease) continue;
        }
        }
        return true;
    }
};