class Solution {
public:
    vector<int> xDir{-1, 1, 0, 0};
    vector<int> yDir{0, 0, 1, -1};

    void dfs(int x, int y, int rows, int cols, vector<vector<int>> &heights, vector<vector<bool>> &visited, set<pair<int,int>> &pacific){
        if(visited[x][y]) return;
        visited[x][y] = true;
        pacific.insert({x,y});
        for(int i = 0; i < 4; ++i){
            int xVal = x + xDir[i];
            int yVal = y + yDir[i];
            if(xVal >= 0 && yVal >= 0 && xVal < rows && yVal < cols && !visited[xVal][yVal] && heights[xVal][yVal] >= heights[x][y]){
                dfs(xVal, yVal, rows, cols, heights, visited, pacific);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        set<pair<int,int>> pacific, atlantic;
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false)), visited2(rows, vector<bool> (cols, false));
        for(int col = 0; col < cols; ++col){
            if(!visited[0][col]){
                dfs(0, col, rows, cols, heights, visited, pacific);
            }
            if(!visited2[rows - 1][col]){
                dfs(rows - 1, col, rows, cols, heights, visited2, atlantic);
            }
        }
        for(int row = 0; row < rows; ++row){
            if(!visited[row][0]){
                dfs(row, 0, rows, cols, heights, visited, pacific);
            }
            if(!visited2[row][cols - 1]){
                dfs(row, cols - 1, rows, cols, heights, visited2, atlantic);
            }
        }
        vector<vector<int>> ans;
        vector<int> sub(2,0);
        for(auto it:pacific){
            if(atlantic.find(it) != atlantic.end()){
                sub[0] = it.first;
                sub[1] = it.second;
                ans.push_back(sub);
            }
        }
        
        return ans;
    }
};