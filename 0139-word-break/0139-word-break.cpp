class Solution {
public:
    bool helper(int idx, string s, string curr, unordered_set<string> &wordDict, vector<int> &mp){
        
        if(idx == s.size()){
            mp[idx] = true;
            return true;
        }
        if(mp[idx] != -1){
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
        vector<int> mp(s.size() + 1, -1);
        for(auto it:wordDict){
            us.insert(it);
        }
        return helper(0, s, "", us, mp);
    }
};