class Solution {
public:
    class curr_max
    {
      public:
        int max = 0, curr = 0;
    };
    unordered_map<int, vector<int>> graph;
    void createGraph(vector<int>& parent)
    {
        for(int i = 1; i < parent.size(); ++i)
        {
            graph[parent[i]].push_back(i);
        }
    }
    
    int dfs(int curr, string &s, int &res)
    {
            int big1 = 0, big2 = 0;
        for (int& j : graph[curr]) {
            int cur = dfs(j, s, res);
            if (s[curr] == s[j]) continue;
            if (cur > big2) big2 = cur;
            if (big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        createGraph(parent);
        int res= 0;
        dfs(0,s, res);
        return res;
    }
};