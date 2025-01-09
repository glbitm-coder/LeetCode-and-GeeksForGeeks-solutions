class Solution {
public:
    vector<int> temp;
    void backtrack(vector<int> &candidates, int target, set<vector<int>> &ans, vector<int> &curr){
        
        if(target < 0) return;
        if(target == 0){
            temp = curr;
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            temp.clear();
            return;
        }
        for(int i = 0; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            // target = target - candidates[i];
            // cout<<target<<" "<<candidates[i]<<"\n"
            backtrack(candidates, target - candidates[i], ans, curr);
            // target = target + candidates[i];
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        set<vector<int>> s;
        backtrack(candidates, target, s, curr);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};