class Solution {
public:

    void createGraph(vector<vector<int>> &edges, vector<vector<int>> &graph){
        for(auto it:edges){
            graph[it[0]][it[1]] = it[2];
            graph[it[1]][it[0]] = it[2];
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> graph(n, vector<int> (n, 1e8));
        createGraph(edges, graph);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j){
                    graph[i][j] = 0;
                }
            }
        }

        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        unordered_map<int,int> mp;
        for(int i = 0; i < n; ++i){
            mp[i] = 0;
            for(int j = 0; j < n; ++j){
                if(graph[i][j] <= distanceThreshold && i != j){
                    mp[i]++;
                }
            }
        }

        int value = INT_MAX;
        int ans = 0;
        for(auto i:mp){
            if(value == i.second){
                ans = max(ans, i.first);
            }
            else {
                if(i.second < value){
                    ans = i.first;
                    value = i.second;
                }
            }  
        }
        return ans;
    }
};