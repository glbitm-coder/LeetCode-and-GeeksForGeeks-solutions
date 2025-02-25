class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ma = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ma = INT_MAX;
                if(i - 1 >= 0)
                    ma = min(ma, grid[i - 1][j]);
                if(j - 1 >= 0)
                    ma = min(ma, grid[i][j - 1]);
                grid[i][j] = (ma == INT_MAX ? grid[i][j] : grid[i][j] + ma);
            }
        }
        return grid[m - 1][n - 1];
    }
};