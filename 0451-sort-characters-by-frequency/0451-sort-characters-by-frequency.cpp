class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i = 0 ; i < (int)s.size(); ++i){
            mp[s[i]]++;
        }
        vector<pair<int, char>> vp;
        for(auto& it: mp)
        {
            vp.push_back({it.second, it.first});
        }
        sort(vp.begin(), vp.end(),  greater<>());
        s = "";
         for(auto& i : vp)
        {
            while(i.first > 0)
            {
                s += i.second;
                --i.first;
            }
        }
        return s;
    }
};