class Solution {
public:
    bool backtrack(int x, int y, vector<vector<char>> &board, int rows, int cols, string word, vector<vector<bool>> &visited)
    {
        if(word == "") return true;
        if(x == rows || y == cols || x == -1 || y == -1) return false;
        if(visited[x][y]) return false;
        if(board[x][y] != word[0]) return false;
        visited[x][y] = true;
        word = word.substr(1);
        bool a = backtrack(x + 1, y, board, rows, cols, word, visited);
        if(a) return true;
        bool b = backtrack(x - 1, y, board, rows, cols, word, visited);
        if(b) return true;
        bool c = backtrack(x, y + 1, board, rows, cols, word, visited);
        if(c) return true;
        bool d = backtrack(x, y - 1, board, rows, cols, word, visited);
        if(d) return true;

        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        bool ans = false;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(word[0] == board[row][col]){
                    ans = backtrack(row, col, board, board.size(), board[0].size(), word, visited);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};