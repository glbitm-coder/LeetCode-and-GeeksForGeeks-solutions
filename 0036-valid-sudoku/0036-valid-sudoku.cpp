class Solution {
public:
    bool checkRowAndCol(vector<vector<char>> &board, int k){
        unordered_set<char> s;
        for(int i = 0; i < 9; ++i)
        {
            if(s.find(board[k][i]) == s.end()){
                s.insert(board[k][i]);
            }
            else
            {
                if(board[k][i] != '.'){
                    s.clear();
                    return false;
                }
            }
        }
        
        s.clear();

        for(int i = 0; i < 9; ++i){
            if(s.find(board[i][k]) == s.end()){
                s.insert(board[i][k]);
            }
            else
            {
                if(board[i][k] != '.'){
                    s.clear();
                    return false;
                }
            }
        }
        s.clear();
        return true;
    }

    bool checkBox(vector<vector<char>> &board, int p, int q){
        unordered_set<char> s;
        for(int i = p; i < p + 3; ++i){
            for(int j = q; j < q + 3; ++j){
                if(s.find(board[i][j]) == s.end()){
                    s.insert(board[i][j]);
                }
                else{
                    if(board[i][j] != '.'){
                        s.clear();
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; ++i)
        {
            if(!checkRowAndCol(board, i)){
                return false;
            }
        }

        for(int i = 0; i < 9; i = i + 3)
        {
            for(int j = 0; j < 9; j = j + 3){
                if(!checkBox(board, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};