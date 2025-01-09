class Solution {
public:
    void backtrack(int idx, vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        backtrack(idx + 1, nums, ans, curr);
        curr.push_back(nums[idx]);
        backtrack(idx + 1, nums, ans, curr);
        curr.pop_back();
        return;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> curr;
        backtrack(0, nums, ans, curr);
        return ans;
    }
};