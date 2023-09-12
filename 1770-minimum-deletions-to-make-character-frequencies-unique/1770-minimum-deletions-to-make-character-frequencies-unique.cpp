class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); ++i){
            mp[s[i]]++;
        }
        vector<int> v;
        for(auto &it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        unordered_set<int> us;
        us.insert(v[v.size() -1]);
        for(int i = v.size() - 2; i >= 0; --i){
            while(us.find(v[i]) != us.end() && v[i] != 0){
                v[i] = v[i] - 1;
                ans += 1;
            }
            us.insert(v[i]);
        }
        return ans;
    }
};