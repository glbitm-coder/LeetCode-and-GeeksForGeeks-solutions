class Solution {
public:
    set<vector<int>> ans;
    void backtrack(int idx, vector<int> &nums, vector<int> &curr){
        if(idx == nums.size()){
            ans.insert(curr);
            return;
        }
        backtrack(idx + 1, nums, curr);
        curr.push_back(nums[idx]);
        backtrack(idx + 1, nums, curr);
        curr.pop_back();
        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, curr);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};