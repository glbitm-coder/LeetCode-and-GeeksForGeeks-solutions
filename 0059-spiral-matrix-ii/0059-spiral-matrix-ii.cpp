class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int r = 0, c = 0, val = 1;
        while(r < n && c < n)
        {
            for(int i = c; i < n - c; ++i)
            {
                ans[r][i] = val;
                ++val;
            }
            ++r;
            for(int i = r; i < n - r + 1; ++i)
            {
                ans[i][n - c - 1] = val;
                ++val;
            }
            ++c;
            for(int i = n - c - 1; i >= c - 1; --i)
            {
                ans[n - r][i] = val;
                ++val;
            }
            for(int i = n - r - 1; i >= r; --i)
            {
                ans[i][c - 1] = val;
                ++val;
            }
        }
        return ans;
    }
};