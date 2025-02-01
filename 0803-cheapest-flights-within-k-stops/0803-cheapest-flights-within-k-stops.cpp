class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Bellman ford
        vector<int> prices(n, INT_MAX), temp(n, INT_MAX);
        int s = 0, d = 0, val = 0;
        prices[src] = 0;
        for(int i = 0; i <= k; ++i){
            temp = prices;
            for(int j = 0; j < flights.size(); ++j){
                s = flights[j][0];
                d = flights[j][1];
                val = flights[j][2];
                if(prices[s] == INT_MAX) continue;
                if(prices[s] + val < temp[d]){
                    temp[d] = prices[s] + val;
                }
            }
            prices = temp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};