class Solution {
public:

    void dfs(int curr, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        if(visited[curr]){
            return;
        }

        visited[curr] = true;

        for(int i = 0; i < isConnected[curr].size(); ++i)
        {
            // cout<<i<<" "<<curr<<" "<<visited[i]<<" "<<isConnected[curr][i]<<"\n";
            if(isConnected[curr][i] == 1 && !visited[i]){
                dfs(i, isConnected, visited);
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();

         int count = 0;
         vector<bool> visited(n, false);
         for(int i = 0; i < n; ++i)
         {
            if(!visited[i])
                dfs(i, isConnected, visited);
            else
                continue;
            count++;
         }

         return count;
    }
};