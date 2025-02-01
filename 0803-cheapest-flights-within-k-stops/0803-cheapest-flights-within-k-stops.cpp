class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Dijkstra
        unordered_map<int, vector<pair<int,int>>> mp;
        vector<vector<int>> dist(n, vector<int> (k + 1, INT_MAX));
        for(int i = 0; i < flights.size(); ++i){
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        dist[src][0] = 0;
        

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,src, -1});
        vector<int> temp;
        int val = 0, s = 0, stops = 0, newStop = 0, newVal = 0;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            val = temp[0];
            s = temp[1];
            stops = temp[2];
            // cout<<s<<" "<<stops<<" "<<val<<" "<<"\n";
            if(s == dst) return val;
            if(stops == k) continue;
            
           
            for(auto it:mp[s]){
                newStop = stops + 1;
                newVal = val + it.second;
                if(dist[it.first][newStop] > newVal){
                    dist[it.first][newStop] = newVal;
                    pq.push({newVal, it.first, newStop});
                }
            }
        }
        
        return -1;
    }
};