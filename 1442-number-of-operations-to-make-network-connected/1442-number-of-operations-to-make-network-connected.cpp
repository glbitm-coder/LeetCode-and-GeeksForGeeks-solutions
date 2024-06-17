class DisjointSet
{
    
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int parentU = findUPar(u);
        int parentV = findUPar(v);
        
        if(parentU == parentV)
            return;
            
        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
    
};

class Solution {
public:

    void createGraph(vector<vector<int>> &connections, unordered_map<int,vector<int>> &graph){

        for(auto it:connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

    }

    int bfs(int n, vector<vector<int>> &connections, vector<bool> &visited, unordered_map<int,vector<int>> &graph){
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        int row = connections.size();
        int col = connections[0].size();
        // vector<bool> visited(n, false);

        // unordered_map<int,vector<int>> graph;
        // createGraph(connections, graph);
        // return bfs(n, connections, visited, graph);

        DisjointSet ds(n);
        int extraEdge = 0;
        for(int i = 0; i < row; ++i){
            if(ds.findUPar(connections[i][0]) == ds.findUPar(connections[i][1])){
                extraEdge++;
            }
            else{
                ds.unionBySize(connections[i][0], connections[i][1]);
            }
        }

        int components = 0;
        for(int i = 0; i < n; ++i){
            if(ds.parent[i] == i){
                components++;
            }
        }

        if(extraEdge >= components - 1){
            return components - 1;
        }
        else{
            return -1;
        }
    }
};