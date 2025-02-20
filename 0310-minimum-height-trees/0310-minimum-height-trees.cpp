class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> inDegree(n, 0);
        for(int i = 0; i < edges.size(); ++i){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < n; ++i){
            if(inDegree[i] == 1){
                q.push(i);
                inDegree[i]--;
            }
        }
        if(q.empty()){
            q.push(0);
        }
        while(!q.empty()){
            int temp = q.front();
            int siz = q.size();
            ans.clear();
            
            for(int i = 0; i < siz; ++i){
                
                temp = q.front();
                ans.push_back(temp);
                q.pop();
                for(auto it:mp[temp]){
                    inDegree[it]--;
                    if(inDegree[it] == 1){
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};