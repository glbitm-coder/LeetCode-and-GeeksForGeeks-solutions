class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        int rows = (int)mat.size();
        int cols = (int)mat[0].size();
        if((rows * cols) == (r * c))
        {
            
            if( r == rows && c == cols)
            {
                return mat;
            }
            vector<int> sub_ans;
            for(int i = 0; i < rows; ++i)
            {
                for(int j = 0; j < cols; ++j)
                {
                    sub_ans.push_back(mat[i][j]);
                    if(sub_ans.size() == c)
                    {
                        ans.push_back(sub_ans);
                        sub_ans.clear();
                    }
                }
            }
            
        }
        else{
            return mat;
        }
        return ans;
    }
};