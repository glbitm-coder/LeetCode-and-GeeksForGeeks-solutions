class Solution {
public:
    void bfs(int curr, int m, vector<vector<int>> &graph, unordered_set<int> &s1, unordered_set<int> &s2, vector<bool> &visited)
    {
        bool val = true;
        queue<int> q;
        q.push(curr);
        q.push(-1);
        while(!q.empty())
        {
            curr = q.front();
            q.pop();

            if(curr == -1){
                if(!q.empty()){
                    q.push(-2);
                    val = false;
                }                
                continue;
            }
            else if(curr == -2){
                if(!q.empty()){     
                    q.push(-1);
                    val = true;
                }
                continue;
            }
            
            visited[curr] = true;
            if(val == true){
                s1.insert(curr);
            }else{
                s2.insert(curr);
            }

            for(int i = 0; i < graph[curr].size(); ++i){
                if(!visited[graph[curr][i]]){
                    q.push(graph[curr][i]);
                }
            }
        }

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();

        unordered_set<int> s1, s2;
        vector<bool> visited(m, false);

        for(int i = 0; i < m; ++i){
            if(!visited[i]){
                bfs(i, m, graph, s1, s2, visited);
            }
        }
        
        // for(auto it:s1){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        // for(auto it:s2){
        //     cout<<it<<" ";
        // }

        for(auto it:s1){
            if(s2.find(it) != s2.end()){
                return false;
            }
        }
        return true;
    }
};