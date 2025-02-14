class Solution {
public:
    int xDir[4] {0, 0, 1, -1};
    int yDir[4] {1, -1, 0, 0};
    
    int dfs(int curr_x, int curr_y, int rows, int cols, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        int val = 4, xVal = 0, yVal = 0;
        int ans = 0;
        visited[curr_x][curr_y] = true;
        for(int i = 0; i < 4; ++i){
            xVal = curr_x + xDir[i];
            yVal = curr_y + yDir[i];
            if(xVal >= 0 && yVal >= 0 && xVal < rows && yVal < cols){
                if(grid[xVal][yVal] == 1){
                    val = val - 1;
                    if(!visited[xVal][yVal]){
                        ans += dfs(xVal, yVal, rows, cols, grid, visited);
                    }
                }
            }
        }
        ans += val;
        return ans;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    return dfs(i, j, n, m, grid, visited);
                }
            }
        }
        return 0;
    }
};