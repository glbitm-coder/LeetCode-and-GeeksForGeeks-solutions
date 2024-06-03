class Solution {
public:

    void dfs(int x, int y, int rows, int cols, vector<vector<char>> &board, vector<vector<bool>> &visited)
    {
        if(visited[x][y]){
            return;
        }

        visited[x][y] = true;
        board[x][y] = '1';

        vector<int> x_val{0, 0, 1, -1};
        vector<int> y_val{1, -1, 0, 0};

        for(int i = 0; i < 4; ++i)
        {
            int xValue = x + x_val[i];
            int yValue = y + y_val[i];

            if(xValue >= 0 && yValue >= 0 && xValue < rows && yValue < cols)
            {
                if(board[xValue][yValue] == 'O' && !visited[xValue][yValue])
                {
                    dfs(xValue, yValue, rows, cols, board, visited);
                }
            } 
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && (board[i][j] == 'O')){
                    dfs(i, j, rows, cols, board, visited);
                }
            }
        }

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};