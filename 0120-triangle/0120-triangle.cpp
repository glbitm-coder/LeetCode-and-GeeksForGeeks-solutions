class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();

        vector<vector<int>> dp(rows);

        int ans = INT_MAX;
        for(int i = 0; i < rows; ++i){
            
            int cols = triangle[i].size();
            
            triangle[i][0] = i == 0 ? triangle[0][0] : triangle[i - 1][0] + triangle[i][0];

            for(int j = 1; j < cols; ++j){
                triangle[i][j] = ((i == j) ? triangle[i - 1][j - 1]  : min(triangle[i - 1][j] , triangle[i - 1][j - 1])) + triangle[i][j];
            }
            
            if(i == rows - 1){
                for(int j = 0; j < cols; ++j){
                    ans = min(ans, triangle[i][j]);
                }   
            }
        }
        return ans;
    }
};