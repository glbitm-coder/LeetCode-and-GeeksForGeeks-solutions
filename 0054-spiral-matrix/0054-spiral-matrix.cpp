class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int i, k = 0, l = 0;
 
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
        while (k < m && l < n) {
            /* Print the first row from
                   the remaining rows */
            for (i = l; i < n; ++i) {
                ans.push_back(matrix[k][i]);
            }
            k++;

            /* Print the last column
             from the remaining columns */
            for (i = k; i < m; ++i) {
                ans.push_back(matrix[i][n - 1]);
            }
            n--;

            /* Print the last row from
                    the remaining rows */
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                   ans.push_back(matrix[m - 1][i]);
                }
                m--;
            }

            /* Print the first column from
                       the remaining columns */
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};