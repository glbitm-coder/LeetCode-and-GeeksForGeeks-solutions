class Solution {
public:
    void dfs(int curr, int n, vector<vector<int>> &graph, vector<bool> &firstVisited, vector<bool> &secondVisited)
    {             
        // cout<<curr<<" "<<firstVisited[curr]<<" "<<secondVisited[curr]<<"\n";  
        firstVisited[curr] = true;
        secondVisited[curr] = true;

        for(int i = 0; i < graph[curr].size(); ++i){
            // cout<<"con "<<graph[curr][i]<<" "<<firstVisited[graph[curr][i]]<<" "<<secondVisited[graph[curr][i]]<<"\n";
            if(firstVisited[graph[curr][i]] && secondVisited[graph[curr][i]]){
                secondVisited[curr] = true;
                return;
            }
            else if(!firstVisited[graph[curr][i]]){
                dfs(graph[curr][i], n, graph, firstVisited, secondVisited);
                //  cout<<"con "<<graph[curr][i]<<" "<<firstVisited[graph[curr][i]]<<" "<<secondVisited[graph[curr][i]]<<"\n";
            
                if(firstVisited[graph[curr][i]] && secondVisited[graph[curr][i]]){
                    secondVisited[curr] =true;
                    return;
                }
            }
        }
        secondVisited[curr] =false;
        // cout<<curr<<" "<<firstVisited[curr]<<" "<<secondVisited[curr]<<"\n";
        return ;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> firstVisited(n, false);
        vector<bool> secondVisited(n, false);
        for(int i = 0; i < n; ++i){
            if(!firstVisited[i]){
                dfs(i, n, graph, firstVisited, secondVisited);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(!firstVisited[i] || !secondVisited[i]){
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};