class Solution {
public:

    void createGraph(vector<vector<int>> &flights, map<int,vector<pair<int,int>>> &graph){

            for(auto it:flights){
                graph[it[0]].push_back({it[1], it[2]});
            }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        set<pair<int,pair<int,int>>> s;

         map<int,vector<pair<int,int>>> graph;

        createGraph(flights, graph);

        s.insert({0,{src,0}});

        map<pair<int,int>,int> priceArr;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= k + 1; ++j){
                priceArr[{i,j}] = INT_MAX;
            }
        }


        while(!s.empty()){
            auto it = *(s.begin());
            int price = it.first;
            int node = it.second.first;
            int valueOfK = it.second.second;

            s.erase(it);

            
            for(auto it:graph[node]){
                int nextNode = it.first;
                int nextPrice = it.second;
                if(priceArr[{nextNode,valueOfK + 1}] > price + nextPrice && valueOfK + 1 <= k + 1){
                    if(priceArr[{nextNode, valueOfK + 1}] != INT_MAX){
                        s.erase({priceArr[{nextNode, valueOfK + 1}], {nextNode, valueOfK + 1}});
                    }
                    
                    priceArr[{nextNode,valueOfK + 1}] = price + nextPrice;
                    s.insert({priceArr[{nextNode,valueOfK + 1}], {nextNode, valueOfK + 1}});
                }
            }

        }
        int ans = INT_MAX;
        for(int i = 0; i <= k + 1; ++i){
                ans = min(ans, priceArr[{dst,i}]);
            }
        return ans == INT_MAX ? -1 : ans;
    }
};