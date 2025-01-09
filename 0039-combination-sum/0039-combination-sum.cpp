class Solution {
public:
    void backtrack(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &curr){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(curr);
        }
        for(int i = 0; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], ans, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(candidates, target, ans, curr);
        set<vector<int>> s;
        for(auto it:ans){
            sort(it.begin(), it.end());
            s.insert(it);
        }
        ans.clear();
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};