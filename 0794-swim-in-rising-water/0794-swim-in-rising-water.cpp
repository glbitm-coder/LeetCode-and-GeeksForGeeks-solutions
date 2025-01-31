class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int visited[n][n];
        for(int i = 0; i <n; ++i){
            for(int j = 0; j < n; ++j){
                visited[i][j] = 0;
            }
        }
        pq.push({{grid[0][0],0,0}});
        int xDir[4] = {0, 0, 1, -1};
        int yDir[4] = {1, -1, 0, 0};
        vector<int> temp;
        int r = 0,c = 0,val = 0, ans = 0, xVal = 0, yVal = 0;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            val = temp[0];
            r = temp[1];
            c = temp[2];
            ans = max(ans, val);
            if(visited[r][c] == 1) continue;
            visited[r][c] = 1;
            if(r == n - 1 && c == n - 1){
                return ans;
            }
            for(int i = 0; i < 4; ++i){
                xVal = r + xDir[i];
                yVal = c + yDir[i];
                if(xVal >= 0 && yVal >= 0 && xVal < n && yVal < n && visited[xVal][yVal] == 0){
                    pq.push({grid[xVal][yVal], xVal, yVal});
                }
            }
        }
        return ans;
    }
};