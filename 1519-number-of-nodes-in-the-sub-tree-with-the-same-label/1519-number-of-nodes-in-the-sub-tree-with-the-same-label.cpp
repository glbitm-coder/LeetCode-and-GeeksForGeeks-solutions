class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, bool> visited;
    vector<int> ans;
    void createGraph(vector<vector<int>>& edges)
    {
        for(auto &it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
    }
    
   vector<int> dfs(int curr, string &labels)
    {
        vector<int> count(26,0);
        if(visited[curr])
        {
            return count;
        }
        visited[curr] = true;
        
        for(auto &it:graph[curr])
        {
            vector<int> temp = dfs(it, labels);
            for(int i = 0; i < 26; ++i)
            {
                count[i] += temp[i];
            }
        }
       int ch = labels[curr] - 'a';
        ++count[ch];
        ans[curr] = count[ch];
        return count;
        
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        createGraph(edges);
        ans.resize(n,1);
        dfs(0, labels);
        return ans;
        
    }
};