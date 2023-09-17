class Solution {
public:
    class tuple
        {
            public:
            int node; // on which current node we are standing
            int mask; // mask of that node
            int cost; // cost of path explore by this node
            tuple(int node, int mask, int cost)
            {
                this -> node = node;
                this -> mask = mask;
                this -> cost = cost;
            }
        };
    int bfsWithMask(int i , unordered_map<int,vector<int>> &mp, int target, set<pair<int,int>> &s, int len){
        queue<tuple> q;
        int ans = INT_MAX;
        tuple nod(i, 1 << i, 0);
        q.push(nod);
        while(!q.empty()){
            tuple p = q.front();
            q.pop();
            if(p.mask == target){
                ans = min(ans, p.cost);
                continue;
            }
            pair<int,int> pr = {p.node, p.mask};
            if(s.find(pr) != s.end()){
                continue;
            }
            s.insert(pr);
            for(auto &it: mp[p.node]){
                if(s.find({it, p.mask | (1 << it)}) == s.end())

                    q.push(tuple(it, p.mask | (1 << it) , p.cost + 1));
            }
        }
        return ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> mp;
        set<pair<int, int>> s;
        int target = (1 << graph.size()) - 1;
        for(int i = 0; i < graph.size(); ++i){
            mp[i] = graph[i];
            
        }
        int len = 0;
        int res = INT_MAX;
        cout<<target<<"\n";
        for(int i = 0; i < graph.size(); ++i){
            res = min(res, bfsWithMask(i, mp, target, s, len));
            s.clear();
        }
        return res;
    }
};