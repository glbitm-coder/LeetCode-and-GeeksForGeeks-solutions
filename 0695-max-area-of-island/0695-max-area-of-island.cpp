class Solution {
public:
    vector<int> xDir{1, -1, 0, 0};
    vector<int> yDir{0, 0, -1, 1};
    int xVal = 0, yVal = 0;
    void dfs(int x, int y, int rows, int cols, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &ans)
    {
        if(visited[x][y]) return;
        visited[x][y] = true;
        ans += 1;
        for(int i = 0; i < 4; ++i){
            xVal = x + xDir[i];
            yVal = y + yDir[i];
            if(xVal >= 0 && yVal >= 0 && xVal < rows && yVal < cols && !visited[xVal][yVal] && grid[xVal][yVal] == 1){
                dfs(xVal, yVal, rows, cols, grid, visited, ans);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0, res = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(i, j, rows, cols, grid, visited, ans);
                    res = max(ans, res);
                    ans = 0;
                }
            }
        }
        return res;
    }
};