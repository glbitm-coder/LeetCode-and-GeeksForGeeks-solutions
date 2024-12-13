class Solution {
public:
    bool checkRow(vector<char> &board){
        unordered_set<char> s;
        for(int i = 0; i < 9; ++i)
        {
            if(s.find(board[i]) == s.end()){
                s.insert(board[i]);
            }
            else
            {
                if(board[i] != '.'){
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
            if(!checkRow(board[i])){
                return false;
            }
        }

        for(int i = 0; i < 9; ++i){
            unordered_set<char> s;
            for(int j = 0; j < 9; ++j){
                if(s.find(board[j][i]) == s.end()){
                    s.insert(board[j][i]);
                }
                else{
                    if(board[j][i] != '.'){
                        s.clear();
                        return false;
                    }
                }
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