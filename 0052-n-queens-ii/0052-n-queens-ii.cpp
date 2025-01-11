class Solution {
public:
    void backtrack(int no, int x, int n, vector<string> &curr, vector<vector<string>> &ans){
        if(no == n + 1){
            vector<string> temp = curr;
            for(int i = 0; i < curr.size(); ++i){
                for(int j = 0; j < curr[i].size(); ++j){
                    if(curr[i][j] == 'a' || curr[i][j] == '.'){
                        temp[i][j] = '.';
                    }
                    else{
                        temp[i][j] = 'Q';
                    }
                }
            }
            ans.push_back(temp);
        }
        if(x == n) return;
        for(int i = 0; i < n; ++i){
           
            if(curr[x][i] == '.'){
                bool isValid = true;
                for(int j = x - 1; j >= 0; --j){
                    if(curr[j][i] == 'Q'){
                        isValid = false;
                        break;
                    }
                }
                if(!isValid) continue;
                for(int j = x - 1, k = i - 1; k >= 0 & j >= 0; --j, --k){
                    if(curr[j][k] == 'Q'){
                        isValid = false;
                        break;
                    }
                }
                if(!isValid) continue;
                for(int j = x - 1, k = i + 1; k < n  && j >= 0;  ++k, --j){
                    if(curr[j][k] == 'Q'){
                        isValid = false;
                        break;
                    }
                }
                if(!isValid) continue;
                curr[x][i] = 'Q';
                backtrack(no + 1, x + 1, n, curr, ans);
                curr[x][i] = '.';
            }
        }
    }
    int solveNQueens(int n) {
        vector<vector<string>> ans;
        string str = "";
        for(int i = 0; i < n; ++i){
            str += ".";
        }
        vector<string> curr(n, str);
        backtrack(1, 0, n, curr, ans);
        return ans.size();
    }
    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};