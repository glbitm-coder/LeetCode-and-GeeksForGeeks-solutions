class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows= (int)mat.size();
        int cols = (int)mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, INT_MAX));
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int,int>> dirxns{{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int curr_x = curr.first;
            int curr_y = curr.second;
            
            for(auto &it: dirxns){
                
                int x = curr_x + it.first;
                int y = curr_y + it.second;
                
                if(x >= 0 && y >= 0 && x < rows && y < cols)
                {
                    if(ans[x][y] > ans[curr_x][curr_y] + 1){
                        ans[x][y] = ans[curr_x][curr_y] + 1;
                        q.push({x,y});
                    }
                }
            }
            
        }
        return ans;
    }
};