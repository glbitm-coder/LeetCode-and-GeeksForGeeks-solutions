class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j){
                
                visited[i][j] = false;

                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        vector<int> x{-1, 0, 1, 0};
        vector<int> y{0, 1, 0, -1};

        
        int ans = 0;
        q.push({-1, -1});
        while(!q.empty())
        {
            pair<int,int> curr = q.front();

            if(curr.first == -1 && curr.second == -1)
            {
                q.pop();
                ans += 1;

                if(!q.empty()){
                    q.push({-1, -1});
                }
                continue;
            }
            q.pop();
            visited[curr.first][curr.second] = true;
            for(int i = 0; i < 4; ++i){
                int var_x = curr.first + x[i];
                int var_y = curr.second + y[i];
                if(var_x >= 0 && var_x < m && var_y >= 0 && var_y < n){
                    if(grid[var_x][var_y] == 1 && !visited[var_x][var_y]){
                        grid[var_x][var_y] = 2;
                        q.push({var_x, var_y});
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans - 1;
    }
};