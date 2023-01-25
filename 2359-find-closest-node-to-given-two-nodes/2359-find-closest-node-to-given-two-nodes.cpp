class Solution {
public:
    unordered_map<int,int> mp;
    void createGraph(vector<int>& edges)
    {
        int n = (int)edges.size();
        for(int i = 0; i < n; ++i)
        {
            mp[i] = edges[i];
        }
    }
    void dfs(int curr, vector<int>& adjList, vector<bool>& visited)
    {
       if(visited[curr]) return;
        visited[curr] = true;
        adjList.push_back(curr);
        if(mp[curr] != -1)
        {
            dfs(mp[curr], adjList, visited);
            return ;
        }
        else
        {
            return;
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        createGraph(edges);
        vector<bool> visited(edges.size(), false);
        vector<int> adjList1, adjList2;
        dfs(node1, adjList1, visited);
        
        for(int i = 0; i < visited.size(); ++i)
        {
            visited[i] = false;
        }
        dfs(node2, adjList2, visited);
        int dist = INT_MAX;
        int ans = INT_MAX;
        unordered_map<int, int> mp1;
        for(int i = 0; i < adjList1.size(); ++i)
        {
            mp1[adjList1[i]] = i;
        }
        
        for(int i = 0; i < adjList2.size(); ++i)
        {
            
            if(mp1.find(adjList2[i]) != mp1.end())
            {
               int pos = mp1[adjList2[i]];
               int d = max(i, pos);
                if(d < dist)
                {
                    dist = d;
                    ans =  adjList2[i];
                }
                else if(d == dist)
                {
                    ans = min(ans, adjList2[i]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};