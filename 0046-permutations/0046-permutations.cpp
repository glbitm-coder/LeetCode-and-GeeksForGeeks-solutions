class Solution {
public:
    void backtrack(unordered_set<int> &visited, vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited.find(nums[i]) != visited.end()) continue;
            visited.insert(nums[i]);
            curr.push_back(nums[i]);
            backtrack(visited, nums, ans, curr);
            curr.pop_back();
            visited.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_set<int> visited;
        backtrack(visited, nums, ans, curr);
        return ans;
    }
};