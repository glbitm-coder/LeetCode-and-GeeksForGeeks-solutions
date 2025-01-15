class Solution {
public:
    bool dfs(int curr, int parent, int target, unordered_map<int, vector<int>> &mp){
        if(curr == target){
            return true;
        }
        
        for(auto it:mp[curr]){
            if(it != parent){
                bool val = dfs(it, curr, target, mp);
                if(val) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> s;
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < edges.size(); ++i){
            if(mp.find(edges[i][0]) == mp.end() || mp.find(edges[i][1]) == mp.end()){
                mp[edges[i][0]].push_back(edges[i][1]);
                mp[edges[i][1]].push_back(edges[i][0]);    
            }
            else{
                bool val = dfs(edges[i][0], -1, edges[i][1], mp);
                if(val) return edges[i];
                else{
                    mp[edges[i][0]].push_back(edges[i][1]);
                    mp[edges[i][1]].push_back(edges[i][0]);
                }
            }
        }
        return edges[0];
    }
};