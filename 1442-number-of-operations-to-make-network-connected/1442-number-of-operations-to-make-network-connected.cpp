class Solution {
public:

    void createGraph(vector<vector<int>> &connections, unordered_map<int,vector<int>> &graph){

        for(auto it:connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int row = connections.size();
        int col = connections[0].size();
        vector<bool> visited(n, false);

        unordered_map<int,vector<int>> graph;
        createGraph(connections, graph);
        queue<int> q;
        int no_of_islands = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    if(visited[node]){
                        continue;
                    }

                    visited[node] = true;
                    for(auto it:graph[node]){
                        if(!visited[it]){
                            q.push(it);
                        }
                    }
                }
                no_of_islands++;
            }
        }
        return n - 1 > connections.size() ? -1 : no_of_islands - 1;
    }
};