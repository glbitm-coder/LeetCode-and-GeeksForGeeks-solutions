class Solution {
public:
    int size;
    vector<int> count, result;
    void dfs(int source, int parent, vector<vector<int>> &graphs)
    {
        for(auto &child:graphs[source])
        {
            if(child != parent)
            {
                dfs(child, source, graphs);
                count[source] += count[child];
                result[source] += (result[child] + count[child]);
            }
        }
    }
    void dfs2(int source, int parent, vector<vector<int>> &graphs)
    {
        for(auto &child:graphs[source])
        {
            if(child != parent)
            {
                result[child] += (result[source] + (size - count[child]) - (result[child] + count[child]));
                dfs2(child, source, graphs);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        size = n;
        vector<vector<int>> graphs;
        graphs.resize(n);
        for(auto &i: edges)
        {
            graphs[i[0]].push_back(i[1]);
            graphs[i[1]].push_back(i[0]);
        }
        count.resize(n,1);
        result.resize(n,0);
        dfs(0, -1,graphs);
        dfs2(0,-1, graphs);
        return result;
        
    }
};