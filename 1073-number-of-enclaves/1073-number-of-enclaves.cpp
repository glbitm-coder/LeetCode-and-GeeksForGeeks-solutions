class Solution {
public:
void dfs(int x, int y, int rows, int cols, vector<vector<int>> &board, vector<vector<bool>> &visited)
    {
        if(visited[x][y]){
            return;
        }

        visited[x][y] = true;
        board[x][y] = 0;

        vector<int> x_val{0, 0, 1, -1};
        vector<int> y_val{1, -1, 0, 0};

        for(int i = 0; i < 4; ++i)
        {
            int xValue = x + x_val[i];
            int yValue = y + y_val[i];

            if(xValue >= 0 && yValue >= 0 && xValue < rows && yValue < cols)
            {
                if(board[xValue][yValue] == 1 && !visited[xValue][yValue])
                {
                    dfs(xValue, yValue, rows, cols, board, visited);
                }
            } 
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && (board[i][j] == 1)){
                    dfs(i, j, rows, cols, board, visited);
                }
            }
        }

        int count = 0;
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == 1){
                    ++count;
                }
            }
        }
        return count;
    }
};