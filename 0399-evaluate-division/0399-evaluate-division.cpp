class Solution {
public:
    unordered_map<string, set<pair<string,double>>> mp;
    double dfs(string curr, string target, unordered_set<string> &visit){
        if(mp.find(curr) == mp.end()) return -1.0;
        if(visit.find(curr) == visit.end()) visit.insert(curr);
        if(curr == target) return 1.0;
        for(auto it:mp[curr]){
            string str = it.first;
            double value = it.second;
            if(visit.find(str) == visit.end()){
                visit.insert(str);
                double val = dfs(str, target, visit);
                if(val != -1.0) return val * value;
            }
        }
        return -1.0;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0; i < equations.size(); ++i){
            mp[equations[i][0]].insert({equations[i][1], values[i]});
            mp[equations[i][1]].insert({equations[i][0], 1 / values[i]});
        }

        vector<double> ans;
        unordered_set<string> visit;
        for(int i = 0; i < queries.size(); ++i){
            ans.push_back(dfs(queries[i][0], queries[i][1], visit));
            visit.clear();
        }
        return ans;
    }
};