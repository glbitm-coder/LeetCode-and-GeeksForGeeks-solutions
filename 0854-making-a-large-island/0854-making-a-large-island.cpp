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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n * n);

        vector<int> xDir{0,0,1,-1};
        vector<int> yDir{1,-1,0,0};

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int num = i * n + j;
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; ++k){
                        int x = i + xDir[k];
                        int y = j + yDir[k];
                        int newNum = x * n + y;
                        if(x >= 0 && y >= 0 && x < n && y < n){
                            if(grid[x][y] == 1){
                                ds.unionBySize(num,newNum);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n * n; ++i){
            ans = max(ans, ds.size[i]);
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int num = i * n + j;
                if(grid[i][j] == 0){
                    unordered_set<int> s;
                    for(int k = 0; k < 4; ++k){
                        int x = i + xDir[k];
                        int y = j + yDir[k];
                        int newNum = x * n + y;
                        if(x >= 0 && y >= 0 && x < n && y < n){
                            if(grid[x][y] == 1){
                                int parent = ds.findUPar(newNum);
                                s.insert(parent);
                            }
                        }
                    }
                    int total = 0;
                    for(auto it:s){
                        total += ds.size[it];
                    }
                    ans = max(ans, total + 1);
                }
            }
        }
        return ans;
    }
};