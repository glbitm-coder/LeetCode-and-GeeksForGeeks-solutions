class Solution {
public:
    vector<int> xDir{1, -1, 0, 0};
    vector<int> yDir{0, 0, -1, 1};
    void dfs(int x, int y, int n, int m, vector<vector<char>> &board, vector<vector<bool>> &visited)
    {
        if(visited[x][y]) return;
        board[x][y] = 'P';
        for(int i = 0; i < 4; ++i){
            int xVal = x + xDir[i];
            int yVal = y + yDir[i];
            if(xVal >= 0 && yVal >= 0 && xVal < n && yVal < m && !visited[xVal][yVal] && board[xVal][yVal] == 'O'){
                dfs(xVal, yVal, n, m, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && !visited[i][j] && board[i][j] == 'O'){
                    dfs(i, j, n, m, board, visited);
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'P'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};