class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;
        vector<pair<int,int>> mp[n+1];
        vector<bool> visited(n + 1, false);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < times.size(); ++i){
            mp[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        pq.push({0,k});
        pair<int,int> temp;
        int u;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            u = temp.second;
            for(auto it:mp[u]){
                if(!visited[it.first] && minTime[it.first] > minTime[u] + it.second){
                    minTime[it.first] = minTime[u] + it.second;
                    pq.push({minTime[it.first], it.first});
                }
            }
        }
        int val = 0;
        for(int i = 1; i <= n; ++i){
            val = max(val, minTime[i]);
        }
        return val == INT_MAX ? -1 : val;
    }
};