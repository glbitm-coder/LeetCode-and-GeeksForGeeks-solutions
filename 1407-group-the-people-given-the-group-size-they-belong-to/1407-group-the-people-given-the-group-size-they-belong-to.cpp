class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < groupSizes.size(); ++i){
            mp[groupSizes[i]].push_back(i);
        }
        vector<int> sub_ans;
        for(int i = 0; i <= groupSizes.size(); ++i){
            if(mp.find(i) == mp.end()){
                continue;
            } else {
                for(auto &it:mp[i]){
                    sub_ans.push_back(it);
                    if(sub_ans.size() >= i){
                        ans.push_back(sub_ans);
                        sub_ans.clear();
                    }
                }
            }
        }
        return ans;
    }
};