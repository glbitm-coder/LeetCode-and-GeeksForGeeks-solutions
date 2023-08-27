class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int target = stones[n - 1];
        map<int, unordered_set<int>> mp;
        mp[0].insert(1);
        for(int i = 0; i < n; ++i){
            if(mp[stones[i]].size() == 0) continue;
            for(auto &it: mp[stones[i]]){
                if(stones[i] + it == target) return true;
                if(it - 1 > 0)
                    mp[stones[i] + it].insert(it - 1);
                mp[stones[i] + it].insert(it);
                mp[stones[i] + it].insert(it + 1);
            }
        }
        return false;
    }
};