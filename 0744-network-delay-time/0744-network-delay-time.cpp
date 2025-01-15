class Solution {
public:
    void dfs(int curr, unordered_map<int, vector<pair<int,int>>> &mp, vector<int> &minTime){
        int temp = 0;
        for(auto it:mp[curr]){
            temp = it.second + minTime[curr - 1];
            if(temp <  minTime[it.first - 1]){
                minTime[it.first - 1] = temp;
                dfs(it.first, mp, minTime);
            }
        }
        return;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTime(n, INT_MAX);
        minTime[k - 1] = 0;
        unordered_map<int, vector<pair<int,int>>> mp;
        for(int i = 0; i < times.size(); ++i){
            mp[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        dfs(k, mp, minTime);
        int val = *max_element(minTime.begin(), minTime.end());
        return val == INT_MAX ? -1 : val;
    }
};