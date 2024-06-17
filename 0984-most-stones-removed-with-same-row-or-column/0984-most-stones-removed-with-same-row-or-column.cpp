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
    int removeStones(vector<vector<int>>& stones) {
        int rows = stones.size();
        int maxRows = 0;
        int maxCols = 0;
        for(int i = 0; i < rows; ++i){
            maxRows = max(maxRows, stones[i][0]);
            maxCols = max(maxCols, stones[i][1]);
        }

        DisjointSet ds(maxRows + 1 + maxCols + 1);
        for(int i = 0; i < rows; ++i){
            int row = stones[i][0];
            int col = maxRows + 1 + stones[i][1];
            if(ds.findUPar(row) == ds.findUPar(col)){
                continue;
            }
            else{
                ds.unionBySize(row, col);
            }
        }

        unordered_set<int> ans;
        for(int i = 0; i < rows; ++i){
            ans.insert(ds.findUPar(stones[i][0]));
            ans.insert(ds.findUPar(stones[i][1] + maxRows + 1));
        }

        return stones.size() - ans.size();
    }
};