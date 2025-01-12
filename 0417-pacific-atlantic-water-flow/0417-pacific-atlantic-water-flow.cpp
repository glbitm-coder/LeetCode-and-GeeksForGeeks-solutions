class Solution {
public:
    set<pair<int,int>> pacific;
    set<pair<int,int>> atlantic;
    vector<int> xDir{-1, 1, 0, 0};
    vector<int> yDir{0, 0, 1, -1};

    void dfs(int x, int y, int rows, int cols, vector<vector<int>> &heights, vector<vector<bool>> &visited){
        if(visited[x][y]) return;
        visited[x][y] = true;
        pacific.insert({x,y});
        for(int i = 0; i < 4; ++i){
            int xVal = x + xDir[i];
            int yVal = y + yDir[i];
            if(xVal >= 0 && yVal >= 0 && xVal < rows && yVal < cols && !visited[xVal][yVal] && heights[xVal][yVal] >= heights[x][y]){
                dfs(xVal, yVal, rows, cols, heights, visited);
            }
        }
    }

    void dfs2(int x, int y, int rows, int cols, vector<vector<int>> &heights, vector<vector<bool>> &visited){
        if(visited[x][y]) return;
        visited[x][y] = true;
        atlantic.insert({x,y});
        for(int i = 0; i < 4; ++i){
            int xVal = x + xDir[i];
            int yVal = y + yDir[i];
            if(xVal >= 0 && yVal >= 0 && xVal < rows && yVal < cols && !visited[xVal][yVal] && heights[xVal][yVal] >= heights[x][y]){
                dfs2(xVal, yVal, rows, cols, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        for(int col = 0; col < cols; ++col){
            if(!visited[0][col]){
                dfs(0, col, rows, cols, heights, visited);
            }
        }
        for(int row = 0; row < rows; ++row){
            if(!visited[row][0]){
                dfs(row, 0, rows, cols, heights, visited);
            }
        }
        for(int i = 0; i < rows; ++i){
            fill(visited[i].begin(), visited[i].end(), false);
        }
        for(int col = 0; col < cols; ++col){
            if(!visited[rows - 1][col]){
                dfs2(rows - 1, col, rows, cols, heights, visited);
            }
        }
        for(int row = 0; row < rows; ++row){
            if(!visited[row][cols - 1]){
                dfs2(row, cols - 1, rows, cols, heights, visited);
            }
        }
        vector<vector<int>> ans;
        for(auto it:pacific){
            if(atlantic.find(it) != atlantic.end()){
                vector<int> sub{it.first,it.second};
                ans.push_back(sub);
                sub.clear();
            }
        }
        
        return ans;
    }
};