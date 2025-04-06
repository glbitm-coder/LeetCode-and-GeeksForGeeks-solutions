class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> s1, s2, ans;
        for(int i = 0; i < edges.size(); ++i){
            s2.insert(edges[i][1]);
        }
        for(int i = 0; i < n; ++i) s1.insert(i);

        for(auto it:s1){
            if(s2.find(it) == s2.end()){
                ans.insert(it);
            }
        }
        if(ans.size() == 1) return *ans.begin();
        if(ans.size() > 1) return -1;
        return 0;
    }
};