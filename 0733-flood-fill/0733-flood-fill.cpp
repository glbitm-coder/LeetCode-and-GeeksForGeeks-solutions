class Solution {
public:

    void dfs(int sr, int sc, int m, int n, int color, vector<vector<int>> &image, vector<vector<bool>> &visited, int target)
    {
        if(visited[sr][sc]){
            return;
        }

        visited[sr][sc] = true;
        image[sr][sc] = color;
        vector<int> x{-1, 1, 0, 0};
        vector<int> y{0, 0, -1, 1};

        for(int i = 0; i < 4; ++i){
            if(sr + x[i] >= 0 && sr + x[i] < m && sc + y[i] >= 0 && sc + y[i] < n)
            {
                if(image[sr + x[i]][sc + y[i]] == target){
                    
                    dfs(sr + x[i], sc + y[i], m, n, color, image, visited, target);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int target = image[sr][sc];
        dfs(sr, sc, m, n, color, image, visited, target);

        return image;
    }
};