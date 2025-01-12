class Solution {
public:
    vector<int> xDir{1, -1, 0, 0};
    vector<int> yDir{0, 0, -1, 1};
    void dfs(int x, int y, int rows, int cols, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        if(x == rows || x == -1 || y == cols || y == -1) return;
        if(visited[x][y]) return;
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int xVal = x + xDir[i];
            int yVal = y + yDir[i];
            if(xVal >= 0 && yVal >= 0 && xVal < rows && yVal < cols && !visited[xVal][yVal] && grid[xVal][yVal] == '1'){
                dfs(xVal, yVal, rows, cols, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i, j, rows, cols, grid, visited);
                    ++ans;
                }
            }
        }
        return ans;
    }
};