class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int start = 0;
        int end = mp[key].size() - 1, mid = -1, ans = -1;
        
        while(start <= end){
            mid = start + (end - start) / 2;
            if(mp[key][mid].first == timestamp){
                return mp[key][mid].second;
            }
            else if(mp[key][mid].first > timestamp){
                end = mid - 1;
            }
            else{
                ans = max(ans,mid);
                start = mid + 1;
            }
        }
        return ans == -1 ? "":mp[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */