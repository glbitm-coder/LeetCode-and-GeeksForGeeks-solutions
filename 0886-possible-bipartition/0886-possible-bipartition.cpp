#define WHITE 0
#define RED 1
#define BLUE 2
class Solution {
public:
    //bipartite graph
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        int len = (int)edges.size();
        unordered_map<int, vector<int> > mp;
        for(int i = 0 ; i < len; ++i)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<string> color(n + 1, "white");
        queue<int> q;
        for(auto i: mp)
        {
            while(!q.empty()) { q.pop(); }
            int curr = i.first;
            if(color[curr] == "white")
            {
                color[curr] = "blue";
                q.push(curr);
                while(!q.empty())
                {
                    int parent = q.front();
                    q.pop();
                    for(int i = 0; i < (int)mp[parent].size(); ++i)
                    {
                        int child = mp[parent][i];
                        if(color[child] == "white")
                        {
                            if(color[parent] == "blue")
                            {
                                color[child] = "red";
                            }
                            else
                            {
                                color[child] = "blue";
                            }
                            q.push(child);
                        }
                        else
                        {
                            if(color[parent] == color[child])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
            
        }
        return true;
    }
};