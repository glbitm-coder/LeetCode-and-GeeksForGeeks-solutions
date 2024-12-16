class TimeMap {
public:
    unordered_map<string,vector<int>> mp;
    map<pair<string,int>,string> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        m[{key,timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        int start = 0;
        int end = mp[key].size() - 1, mid = 0, ans = 0;
        
        while(start <= end){
            mid = start + (end - start) / 2;
            if(mp[key][mid] == timestamp){
                return m[{key,timestamp}];
            }
            else if(mp[key][mid] > timestamp){
                end = mid - 1;
            }
            else{
                ans = max(ans,mp[key][mid]);
                start = mid + 1;
            }
        }
        return m[{key, ans}];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */