class Solution {
public:

    void createGraph(vector<vector<int>>& roads, unordered_map<long long,vector<pair<long long,long long>>> &graph){
        for(auto it:roads){
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
    }
    int shortestTime(int n, unordered_map<long long,vector<pair<long long,long long>>> &graph){
        int mod = 1e9 + 7;

        set<pair<long long,long>> s;
        vector<long long> timeArr(n, LONG_MAX);
        vector<long long> ans(n, 0);

        timeArr[0] = 0;
        s.insert({0, 0});
        ans[0] = 1;


        while(!s.empty()){
            auto it = *(s.begin());
            long long time = it.first;
            long long node = it.second;

            s.erase(it);

            for(auto it: graph[node]){
                long long nextNode = it.first;
                long long nextTime = it.second;
                
                if(timeArr[nextNode] > nextTime + time){
                    if(timeArr[nextNode] != INT_MAX){
                        s.erase({timeArr[nextNode], nextNode});
                    }
                    timeArr[nextNode] = nextTime + time;
                    s.insert({timeArr[nextNode], nextNode});
                    ans[nextNode] = ans[node] % mod;
                }
                else if(timeArr[nextNode] == nextTime + time){
                    ans[nextNode] = ((ans[node] % mod) + (ans[nextNode] % mod)) % mod;
                }
            }
        }
        return ans[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long,vector<pair<long long,long long>>> graph;

        createGraph(roads, graph);
        return shortestTime(n,graph);
    }
};