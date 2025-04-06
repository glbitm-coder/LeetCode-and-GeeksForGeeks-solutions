class Solution {
public:
    set<pair<int,int>> visited, sub;
    int xDir[4] {-1, 1, 0, 0};
    int yDir[4] {0, 0, 1, -1};

    void dfs(int x, int y, vector<vector<int>> &grid)
    {
        if(visited.find({x,y}) != visited.end()) return ;
        int ans = 0, res = 0;
        visited.insert({x,y});

        for(int i = 0; i < grid.size(); ++i){
            
            if(grid[i][y] == 1 && visited.find({i, y}) == visited.end()){
                dfs(i , y, grid);
                sub.insert({x, y});
                sub.insert({i, y});
            }
        }
        for(int i = 0; i < grid[0].size(); ++i){
            
            if(grid[x][i] == 1 && visited.find({x, i}) == visited.end()){
                dfs(x , i, grid);
                sub.insert({x, y});
                sub.insert({x, i});
            }
        }
        return ;


    }

    int countServers(vector<vector<int>>& grid) {
        
        int ans = 0;    
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1 && visited.find({i,j}) == visited.end()){
                    dfs(i, j, grid);
                }
            }
        }
        return sub.size();
    }
};