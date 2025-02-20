class Solution {
public:
    unordered_map<string, vector<int>> mp;

    void dfs(int curr, vector<vector<string>>& accounts, vector<bool> &visited, set<string> &us){
        
        visited[curr] = true;
        for(int i = 1; i < accounts[curr].size(); ++i){
            string str = accounts[curr][i];
            us.insert(str);
            for(auto it: mp[str]){
                if(!visited[it]){
                    dfs(it, accounts, visited, us);
                }
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                mp[accounts[i][j]].push_back(i);
            }
        }

        set<string> us;
        vector<vector<string>> ans;
        vector<string> s;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                dfs(i, accounts, visited, us);
                s.push_back(accounts[i][0]);
                for(auto it: us){
                    s.push_back(it);
                }
                ans.push_back(s);
                s.clear();
                us.clear();

            }
        }
        return ans;
    }
};