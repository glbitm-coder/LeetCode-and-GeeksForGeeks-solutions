class Solution {
public:
    vector<string> ans;
    void dfs(string curr, unordered_map<string, multiset<string>> &mp){
        if(mp.find(curr) == mp.end()){
            ans.push_back(curr);
            return;
        }

        while(mp[curr].size() > 0){
            auto next = *(mp[curr].begin());
            mp[curr].erase(mp[curr].find(next));
            dfs(next, mp);
        }
        ans.push_back(curr);
        return;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for(auto it:tickets){
            mp[it[0]].insert(it[1]);
        }
        // for(auto it:mp){
        //     sort(mp[it.first].rbegin(), mp[it.first].rend());
        // }
        dfs("JFK", mp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};