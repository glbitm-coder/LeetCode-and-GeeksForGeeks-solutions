class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int> > mp;
        int m = (int)edges.size();
        for(int i = 0 ; i < m; ++i)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<int> visited(n, 0);
        
        q.push(source);
        visited[source] = 1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(curr == destination)
            {
                return true;
            }
            for(int i = 0; i < (int)mp[curr].size(); ++i)
            {
                if(visited[mp[curr][i]] == 0)
                {
                    visited[mp[curr][i]] = 1;
                    q.push(mp[curr][i]);
                }
            }
        }
        return false;
    }
};