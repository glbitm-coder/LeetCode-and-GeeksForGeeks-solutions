class Solution {
public:
    bool helper(int idx, string s, string curr, unordered_set<string> &wordDict, unordered_map<int, bool> &mp){
        
        if(idx == s.size()){
            mp[idx] = true;
            return true;
        }
        if(mp.find(idx) != mp.end()){
            return mp[idx];
        }
        for(int i = idx; i <s.size(); ++i ){
            curr = curr + s[i];
            if(wordDict.find(curr) != wordDict.end()){
                bool val = helper(i + 1, s, "", wordDict, mp);
                if(val){
                    mp[idx] = val;
                    return val;
                }
            }
        }
        mp[idx] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        unordered_map<int, bool> mp;
        for(auto it:wordDict){
            us.insert(it);
        }
        return helper(0, s, "", us, mp);
    }
};