class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        for(int i = n - 2; i >= 0; --i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(j == 0 || j == m - 1)
                {
                    if(j == 0 && j == m - 1)
                    {
                        matrix[i][j] += matrix[i + 1][j];
                    }
                    else if(j == 0)
                    {
                        matrix[i][j] += min(matrix[i + 1][j], matrix[i + 1][j + 1] );
                    }
                    else
                    {
                        matrix[i][j] += min(matrix[i + 1][j], matrix[i + 1][j - 1] );
                    }
                }
                else{
                    matrix[i][j] += min( matrix[i + 1][j - 1],min(matrix[i + 1][j], matrix[i + 1][j + 1]));
                }
                    
            }
        }
         return  *min_element(matrix[0].begin(), matrix[0].end());
        
    }
};