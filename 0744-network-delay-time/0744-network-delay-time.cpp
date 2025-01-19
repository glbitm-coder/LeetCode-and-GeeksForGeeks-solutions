class Solution {
public:
    void dfs(int curr, vector<pair<int,int>> mp[], vector<int> &minTime){
        int temp = 0;
        for(auto it:mp[curr]){
            temp = it.second + minTime[curr];
            if( temp <  minTime[it.first]){
                minTime[it.first] = temp;
                dfs(it.first, mp, minTime);
            }
        }
        return;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTime(n + 1, INT_MAX);
        minTime[k] = 0;
        vector<pair<int,int>> mp[n+1];
        for(int i = 0; i < times.size(); ++i){
            mp[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        dfs(k, mp, minTime);
        int val = 0;
        for(int i = 1; i <= n; ++i){
            val = max(val, minTime[i]);
        }
        return val == INT_MAX ? -1 : val;
    }
};