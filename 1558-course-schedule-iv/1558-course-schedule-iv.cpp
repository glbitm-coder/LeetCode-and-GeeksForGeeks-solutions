class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> mp;
        vector<bool> visited(numCourses, false);

        for(int i = 0; i < prerequisites.size(); ++i){
            mp[prerequisites[i][0]].insert(prerequisites[i][1]);
        }
        
        queue<int> q;
        unordered_set<int> s;
        for(int i = 0; i < numCourses; ++i){
            q.push(i);
            s.insert(i);
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(auto it:mp[temp]){
                    if(s.find(it) == s.end()){
                        s.insert(it);
                        q.push(it);
                    }
                }
            }
            mp[i] = s;
            s.clear();
        }    
        vector<bool> ans;
        for(int i = 0; i < queries.size(); ++i){
            if(mp[queries[i][0]].find(queries[i][1]) != mp[queries[i][0]].end()){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};