class Solution {
public:
    bool static cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.second != b.second){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < mat.size(); ++i){
            for(int j = 0; j < mat[i].size(); ++j){
                if(mat[i][j] == 0){
                    if(mp.find(i) == mp.end()){
                        mp[i] = 0;
                    }
                    break;
                }
                mp[i]++;
            }
        }
        vector<pair<int,int>> v;
        for(auto &it:mp){

            pair<int,int> p = {it.first, it.second};
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};