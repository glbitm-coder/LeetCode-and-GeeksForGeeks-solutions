class Solution {
public:
    void dfs(int curr, unordered_map<int,int> &inDegree, unordered_map<int, vector<int>> &mp, vector<int> &ans, vector<bool> &visited){
        visited[curr] = true;

        ans.push_back(curr);
        
        for(auto it:mp[curr]){
            inDegree[it]--;
            if(!visited[it] && inDegree[it] == 0){
                dfs(it, inDegree, mp, ans, visited);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int> inDegree;
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(numCourses, false);
        vector<int> ans;

        for(int i = 0; i < numCourses; ++i){
            inDegree[i] = 0;
        }
        for(auto it:prerequisites){
            inDegree[it[0]]++;
            mp[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i] == 0 && !visited[i]){
                dfs(i, inDegree, mp, ans, visited);
            }
        }
        if(ans.size() != numCourses) ans.resize(0);
        return ans;
    }
};