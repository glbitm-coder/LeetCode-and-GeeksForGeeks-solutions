class Solution {
public:
    void createGraph(vector<vector<int>>& times, unordered_map<int, vector<pair<int,int>>> &graph)
    {
        for(auto it:times){
            graph[it[0]].push_back({it[1],it[2]});
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        createGraph(times, graph);

        set<pair<int,int>> s;
        vector<int> ans(n + 1, INT_MAX);
        ans[k] = 0;
        s.insert({0, k});

        while(!s.empty())
        {
            auto it = *(s.begin());
            int time = it.first;
            int node = it.second;

            s.erase(it);

            for(auto it:graph[node])
            {
                if(ans[it.first] > time + it.second)
                {
                    if(ans[it.first] != INT_MAX)
                    {
                        s.erase({ans[it.first], it.first});
                    }
                    ans[it.first] = time + it.second;
                    s.insert({ans[it.first], it.first});
                }
            }
        }

        int res = -1;
        for(int i = 1; i <= n; ++i)
        {
            res = max(res, ans[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};