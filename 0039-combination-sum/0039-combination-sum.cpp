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
            curr.push_back(candidates[i]);
            backtrack(i, candidates, target - candidates[i], curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> curr;
        backtrack(0, candidates, target,  curr);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};