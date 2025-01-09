class Solution {
public:
    set<vector<int>> ans;
    void backtrack(int prev , vector<int> &candidates, int target, vector<int> &curr){
        if(target < 0) return;
        if(target == 0){
            ans.insert(curr);
            return;
        }
        for(int i = prev; i < candidates.size(); ++i){
            if(target - candidates[i] < 0) return;
            if(i > 0 && candidates[i] == candidates[i-1] && i > prev) continue;
            curr.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target,  curr);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};