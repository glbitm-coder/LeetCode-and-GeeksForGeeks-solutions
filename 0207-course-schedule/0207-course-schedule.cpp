class Solution {
public:
    void dfs(int curr, unordered_map<int,vector<int>> &mp, bool &ans, vector<bool> &todo, vector<bool> &completed){
        if(todo[curr]) {
            ans = false;
            return;
        }
        if(completed[curr]) {
            return;
        }
        todo[curr] = true;
        completed[curr] = true;

        for(auto it:mp[curr]){
            dfs(it, mp, ans, todo, completed);
        }
        todo[curr] = false;
        return;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < n; ++i){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        bool ans = true;
        vector<bool> completed(numCourses, false), todo(numCourses, false);
        for(int i = 0; i < numCourses; ++i){
            if(!completed[i]){
                dfs(i, mp, ans, todo, completed);
            }
        }
        return ans; 
    }
};