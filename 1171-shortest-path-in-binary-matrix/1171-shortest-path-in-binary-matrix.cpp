class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,pair<int,int>>> s;

        s.insert({0,{0,0}});

        map<pair<int,int>,int> dist;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[{i,j}] = INT_MAX;
            }
        }
        dist[{0,0}] = 0;
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        while(s.size() != 0){
            auto it = *(s.begin());
            int xValue = it.second.first;
            int yValue = it.second.second;
            int distance = it.first;

            s.erase(it);

            vector<int> xDir{0,0,1,-1,1,-1,1,-1};
            vector<int> yDir{1,-1,0,0,-1,-1,1,1};

            if(xValue == n - 1 && yValue == n - 1){
                continue;
            }
            for(int i = 0; i < 8; ++i){
                int upDatedX = xValue + xDir[i];
                int upDatedY = yValue + yDir[i];
                if(upDatedX >= 0 && upDatedY >= 0 && upDatedX < n && upDatedY < n){
                    // cout<<xValue<<" "<<yValue<<" "<<upDatedX<<" "<<upDatedY<<"\n";
                    if(grid[upDatedX][upDatedY] == 0 && dist[{upDatedX,upDatedY}] > dist[{xValue,yValue}] + 1){
                        if(dist[{upDatedX, upDatedY}] != INT_MAX)
                        {
                            s.erase({dist[{upDatedX,upDatedY}],{upDatedX,upDatedY}});
                        }
                        dist[{upDatedX, upDatedY}] = dist[{xValue, yValue}] + 1;
                        s.insert({dist[{upDatedX,upDatedY}],{upDatedX, upDatedY}});
                    }
                }
            }
        }
        if(dist[{n - 1, n - 1}] == INT_MAX){
            return -1;
        }
        return dist[{n - 1, n - 1}] + 1;
    }
};