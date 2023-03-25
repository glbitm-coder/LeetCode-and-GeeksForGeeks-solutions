class Solution {
public:
    vector<bool> visited;
    unordered_map<int, vector<int>> graph;
    void createGraph( vector<vector<int>>& edges)
    {
        for(int i = 0; i < edges.size(); ++i)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    void dfs(int curr, vector<int>& sub_ans)
    {
        if(visited[curr])
        {
            return ;
        }
        visited[curr] = true;
        sub_ans.push_back(curr);
        for(auto &it: graph[curr])
        {
            if(!visited[it])
            {
                dfs(it, sub_ans);
            }
        }
        return ;
    }
    
    long long visitAll(int n)
    {
        vector<long long> vertexInComp;
        vector<int> sub_ans;
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                dfs(i, sub_ans);
                vertexInComp.push_back(sub_ans.size());
                sub_ans.clear();
            }
        }
        long long ans = 0;
        sort(vertexInComp.begin(), vertexInComp.end(), greater<long long>());
        long long si = vertexInComp.size();
        vector<long long> prefix(si, 0);
        prefix[si - 1] = 0;
        for(long long i = si - 2; i >= 0; --i)
        {
            prefix[i] = prefix[i + 1] + vertexInComp[i + 1];
        }
        for(long long i =  0; i < si; ++i)
        {
            ans += ((long long)prefix[i] * (long long)vertexInComp[i]);
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        createGraph(edges);
        return visitAll(n);
    }
};