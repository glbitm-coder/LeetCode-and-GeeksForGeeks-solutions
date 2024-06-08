class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &adj) {
        //bfs
        //kahn's algo
        vector<int> inDegree(V, 0);
	    for(int i = 0; i < V; ++i){
	        for(int j = 0; j < adj[i].size(); ++j){
	            inDegree[adj[i][j]]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < inDegree.size(); ++i){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    int count = 0;
	    while(!q.empty()){
	        int curr = q.front();
	        ++count;
	        q.pop();
	        for(int i = 0; i < adj[curr].size(); ++i){
	            if(inDegree[adj[curr][i]] == 0){
	                continue;
	            }
	            inDegree[adj[curr][i]]--;
	            if(inDegree[adj[curr][i]] == 0){
	                q.push(adj[curr][i]);
	            }
	        }
	    }
	    return count!=V;
        
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int> ());
        for(int i = 0; i < prerequisites.size(); ++i){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        if(isCyclic(numCourses, adj)){
            return false;
        }
        return true;
    }
};