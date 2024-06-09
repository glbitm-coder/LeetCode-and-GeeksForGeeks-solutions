class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &adj, vector<int> &ans) {
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
            ans.push_back(curr);
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
	    if( count != V){
            ans.resize(0);
            return true;
        }              
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int> ());
        vector<int> ans;
        for(int i = 0; i < prerequisites.size(); ++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        isCyclic(numCourses, adj, ans);
            
        
        return ans;

    }
};