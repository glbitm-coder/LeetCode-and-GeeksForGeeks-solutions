class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //Prism
        int n = points.size(), x1 = 0, y1 = 0, x2 = 0, y2 = 0, dis, idx, val, ans = 0;
        unordered_map<int, vector<pair<int,int>>> mp;
        for(int i = 0; i < points.size(); ++i){
            x1 = points[i][0];
            x2 = points[i][1];
            for(int j = i + 1; j < points.size(); ++j){
                y1 = points[j][0];
                y2 = points[j][1];
                dis = abs(x1 - y1) + abs(x2 - y2);
                mp[i].push_back({dis, j});
                mp[j].push_back({dis, i});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_set<int> visited;
        pq.push({0,0});
        pair<int,int> p;

        while(visited.size() < n){
            p = pq.top();
            val = p.first;
            idx = p.second;
            pq.pop();
            if(visited.count(idx)) continue;
            ans += val;
            visited.insert(idx);
            for(int i = 0; i < mp[idx].size(); ++i){
                if(!visited.count(mp[idx][i].second)){
                    pq.push({mp[idx][i].first, mp[idx][i].second});
                }
            }
        }
        return ans;
        
    }
};