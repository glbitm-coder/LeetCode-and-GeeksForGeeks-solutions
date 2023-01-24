class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = (int)board.size();
        vector<int> board1D(n*n, -1);
        for(int i = n-1 , cnt = 0; i >= 0 ; --i)
        {
            for(int j = 0; j < n && cnt < n * n; ++j)
            {
                if(board[i][j] != -1)
                {
                    board1D[cnt] = board[i][j] - 1;
                }
                ++cnt;
            }
            --i;
            for(int j = n - 1; j >= 0 && cnt < n * n; --j)
            {
                if(board[i][j] != -1)
                {
                    board1D[cnt] = board[i][j] - 1;
                }
                ++cnt;
            }
        }
        
        //DFS
        vector<int>dist(n*n, INT_MAX);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int i = 1; i <= 6 && curr + i < n * n; ++i)
            {
                int next = board1D[i + curr] != -1 ? board1D[i + curr] : i + curr;
                if(dist[next] == INT_MAX)
                {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
        return dist[n * n -1] == INT_MAX ? -1 : dist[n * n - 1];
    }
};