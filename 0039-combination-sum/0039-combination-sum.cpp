class Solution {
public:
    void backtrack(int prev , vector<int> &candidates, int target, set<vector<int>> &ans, vector<int> &curr){
        if(target < 0) return;
        if(target == 0){
            ans.insert(curr);
            return;
        }
        for(int i = prev; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            backtrack(i, candidates, target - candidates[i], ans, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> curr;
        set<vector<int>> s;
        backtrack(0, candidates, target, s, curr);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};