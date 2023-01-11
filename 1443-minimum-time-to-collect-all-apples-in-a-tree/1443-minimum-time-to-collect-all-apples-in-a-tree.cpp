class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, bool> visited;
    void createGraph(vector<vector<int>>&edges)
    {
        for(auto &it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
    }
    int dfs(int curr, vector<bool>& hasApple)
    {
        if(visited[curr])
        {
            return 0;
        }
        visited[curr] = true;
        int ans = 0;
        for(auto it:graph[curr])
        {
            ans += dfs(it,hasApple);
        }
        if((hasApple[curr] || ans != 0) && curr != 0)
        {
            return ans += 2;
        }
        return ans;
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        createGraph(edges);
        return dfs(0, hasApple);
    }
};