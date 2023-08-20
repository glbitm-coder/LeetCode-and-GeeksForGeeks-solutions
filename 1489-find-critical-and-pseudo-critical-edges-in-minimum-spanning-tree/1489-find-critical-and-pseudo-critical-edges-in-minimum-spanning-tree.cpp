class Solution {
public:
    class UnionFind{
        public:
        int size;
        vector<int> parents;
         
        UnionFind(int n){
            parents.resize(n);
            for(int i = 0; i < n; ++i)
            {
                parents[i] = i;
            }
            size = n;
        }
        
        int find(int n){
            if(parents[n] == n) return n;
            
            int root = find(parents[n]);
            parents[n] = root;
            return root;
        }
        
        bool Union(int i, int j){
            int root_i = find(i);
            int root_j = find(j);
            
            if(root_i != root_j)
            {
                parents[root_i] = root_j;
                --size;
                return true;
            }
            return false;
        }
        
    };
    int findMSTCost(int n, vector<vector<int>>& edges, vector<int>& include, vector<int>& exclude)
    {
        UnionFind uf(n);
        int cost = 0;
        if(include.size() != 0)
        {
            uf.Union(include[0],include[1]);
            cost += include[2];
        }
        for(auto &edge: edges)
        {
            if(exclude != edge && uf.Union(edge[0], edge[1])){
                cost += edge[2];
            }
        }
        for(int i = 0; i < n; ++i){
            if(uf.find(i) != uf.find(0)) return INT_MAX;
        }
        return cost;
    }
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        vector<int> critical_edges;
        vector<int> pseudo_critical_edges;
        vector<int> include;
        vector<int> exclude;
        
         for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
         }
        
        sort(edges.begin(), edges.end(), cmp);
        
        int minCost = findMSTCost(n, edges, include, exclude);
        
        for(int i = 0; i < edges.size(); ++i)
        {
           int excludeCost = findMSTCost(n, edges, include, edges[i]);
            if(excludeCost > minCost)
            {
                critical_edges.push_back(edges[i][3]);
            }
            else{
                int includeCost = findMSTCost(n, edges, edges[i], exclude);
                if(includeCost == minCost)
                {
                    pseudo_critical_edges.push_back(edges[i][3]);
                }
            }
        }
        ans.push_back(critical_edges);
        ans.push_back(pseudo_critical_edges);
        return ans;
    }
};