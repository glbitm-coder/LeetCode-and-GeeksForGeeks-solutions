class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        
        for(auto &it: roads){
            graph[it[0]].insert(it[1]);
            graph[it[1]].insert(it[0]);
        }
        int ans = 0, max_ans = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                ans = graph[i].size() + graph[j].size();
                if(graph[j].find(i) != graph[j].end())
                    --ans;
                
                max_ans = max(ans, max_ans);
            }
        }
        return max_ans;
    }
};