class Solution {
public:
    struct Edge {
    int src, dest, weight;
    };
 
    unordered_map<string,vector<string>> relations;
    unordered_map<string, unordered_map<string,double>> relations_values;
    unordered_map<string, bool> visited;
    void createGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        for(int i = 0; i < equations.size(); ++i)
        {
            relations[equations[i][0]].push_back(equations[i][1]);
            relations[equations[i][1]].push_back(equations[i][0]);
            
            
            relations_values[equations[i][0]][equations[i][1]] = values[i];
            relations_values[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
    }
     void makeUnvisited()
     {
         for(auto &it:relations)
         {
             visited[it.first] = false;
         }
     }
    double dfs(string src, string des)
    {
        double result = -1.0;
        visited[src] = true;
        if(src == des) return 1.0;
        // cout<<src<<" "<<des<<"\n";
        for(auto &it: relations[src])
        {
            if(visited[it]) continue;
            double a = dfs(it, des);
            // cout<<a;
            if(a != -1.0)
            {
                // cout<<src<<" "<<it<<"\n";
                result = a * relations_values[src][it];
                return result;
                
            }
        }
        return result;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        createGraph(equations, values);
        vector<double> ans;
        // for(auto &it:relations)
        // {
        //     cout<<it.first<<"->";
        //     vector<string> a = it.second;
        //     for(int i = 0; i < a.size(); i++)
        //     {
        //         cout<<a[i]<<relations_values[it.first][a[i]]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int i = 0; i < queries.size(); ++i)
        {
            makeUnvisited();
            double result = 1.0;
            if(relations.find(queries[i][0]) == relations.end())
            {
                result = -1;
                ans.push_back(result);
                continue;
            }
            if(relations.find(queries[i][1]) == relations.end())
            {
                result = -1;
                ans.push_back(result);
                continue;
            }
            
            string src = queries[i][0];
            string des = queries[i][1];
            
            result = dfs(src, des);
            
            
            ans.push_back(result);
            cout<<"\n";
        }
        
        return ans;
    }
};