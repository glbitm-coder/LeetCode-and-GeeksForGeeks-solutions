class DisjointSet
{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int parentU = findUPar(u);
        int parentV = findUPar(v);
        
        if(parentU == parentV)
            return;
            
        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
    
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                v.push_back({grid[i][j], i * n + j});
            }
        }

        sort(v.begin(), v.end());
        
        vector<int> xDir{0,0,1,-1};
        vector<int> yDir{1,-1,0,0};

        int ans = 0;

        DisjointSet ds(n * n);
        for(auto it:v){
            int i = it.second / n;
            int j = it.second % n;
            int num = i * n + j;
            for(int k = 0; k < 4; ++k){
                int x = i + xDir[k];
                int y = j + yDir[k];
                int newNum = x * n + y;
                if(x >= 0 && y >= 0 && x < n && y < n){
                    if(grid[x][y] <= grid[i][j]){
                        ds.unionBySize(num, newNum);
                    }
                }
            }
            if(ds.findUPar(0) == ds.findUPar(n * n - 1)){
                return grid[i][j];
            }
        }
        return 0;
    }
};