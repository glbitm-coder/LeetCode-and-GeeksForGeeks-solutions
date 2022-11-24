class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; ++i)
        {
            vector<int> sub_ans;
            for(int j = 1; j <= i; ++j)
            {
                sub_ans.push_back(0);
            }
            ans.push_back(sub_ans);
            sub_ans.clear();
        }
        for(int i = 0; i < ans.size(); ++i)
        {
            for(int j = 0; j < ans[i].size(); ++j)
            {
                if(j == 0 || j == ans[i].size() - 1)
                {
                    ans[i][j] = 1; 
                }
                else{
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }
        }
        return ans;
    }
};