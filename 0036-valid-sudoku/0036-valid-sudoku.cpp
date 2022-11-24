class Solution {
public:
    vector<bool> occur = vector<bool>(10);
    bool isrowValid(vector<vector<char>>& board)
    {
        for(int i = 0; i < (int)board.size(); ++i)
        {
            for(int j = 0; j <= 9; ++j)
            {
                occur[j] = false;
            }
            for(int j = 0; j < (int)board[0].size(); ++j)
            {
                if(board[i][j] != '.')
                {
                    if(occur[(int)(board[i][j] - '0')]){
                        return false;
                    }
                     else{
                         occur[(int)board[i][j] - '0'] = true;
                     }         
                }
            }
        }
        return true;
    }
    bool iscolValid(vector<vector<char>>& board)
    {
        for(int i = 0; i < (int)board[0].size(); ++i)
        {
            for(int j = 0; j <= 9; ++j)
            {
                occur[j] = false;
            }
            for(int j = 0; j < (int)board.size(); ++j)
            {
                if(board[j][i] != '.')
                {
                    if(occur[(int)(board[j][i] - '0')]){
                        return false;
                    }
                     else{
                         occur[(int)board[j][i] - '0'] = true;
                     }         
                }
            }
        }
        return true;
    }
    bool isboxValid(vector<vector<char>>& board, int start_row, int start_col)
    {
        for(int j = 0; j <= 9; ++j)
        {
            occur[j] = false;
        }
        for(int i = start_row; i < start_row + 3; ++i)
        {
            for(int j = start_col; j < start_col + 3; ++j)
            {
                if(board[i][j] != '.')
                {
                    if(occur[(int)(board[i][j] - '0')]){
                        return false;
                    }
                     else{
                         occur[(int)board[i][j] - '0'] = true;
                     }         
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(isrowValid(board) == false || iscolValid(board) == false)
        {
            return false;
        }
        for(int i = 0; i < (int)board.size(); i = i + 3)
        {
            for(int j = 0; j < (int)board[0].size(); j = j + 3)
            {
                if(isboxValid(board, i , j) == false)
                {
                    return false;
                }
            }
        }

            return true;
    }
};