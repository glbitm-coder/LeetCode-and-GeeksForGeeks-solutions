class Solution {
public:
    
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> rows(row, 0);
        vector<int> cols(col, 0);

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if((rows[i] > 1 || cols[j] > 1) && grid[i][j] == 1){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};