class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i <numRows; ++i){
            vector<int> sub_ans(i + 1);
            for(int j = 0; j <= i; ++j){
                if(j == 0){
                    sub_ans[j] = 1;
                    continue;
                }
                if(i == j){
                    sub_ans[j] = 1;
                    continue;
                }
                sub_ans[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(sub_ans);
        }
        return ans;
    }
};