class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int visited[n + 1];
        for(int i = 0; i <= n; ++i) visited[i] = 0;

        for(int i = 0; i < trust.size(); ++i){
            visited[trust[i][0]] = 1;
        }

        vector<int> ans;
        for(int i = 1; i <= n; ++i){
            if(visited[i] == 0){
                ans.push_back(i);
            }
        }

        int count = 0;
        for(int i = 0; i < ans.size(); ++i){
            count = 0;
            for(int j = 0; j < trust.size(); ++j){
                if(trust[j][1] == ans[i]) ++count;
            }
            if(count == n - 1) return ans[i];
        }
        return -1;
    }
};