class Solution {
public:
    vector<string> ans;
    void dfs(string curr, unordered_map<string, vector<pair<string,bool>>> &mp){
        if(mp.find(curr) == mp.end()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < mp[curr].size(); ++i){
            if(mp[curr][i].second == false){
                mp[curr][i].second = true;
                dfs(mp[curr][i].first, mp);
            }
        }
        ans.push_back(curr);
        return;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<pair<string,bool>>> mp;
        for(auto it:tickets){
            mp[it[0]].push_back({it[1],false});
        }
        for(auto it:mp){
            sort(mp[it.first].begin(), mp[it.first].end());
        }
        dfs("JFK", mp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};