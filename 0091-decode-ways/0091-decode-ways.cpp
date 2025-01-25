class Solution {
public:
    int helper(string s, unordered_set<string> &us, unordered_map<string, int> &mp){
        if(s.size() == 0){
            return 1;
        }
        if(s.size() == 1){
            if(s == "0") return 0;
            else{
                mp[s] = 1;
                return 1;
            }
        } 

        string str = "";
        int ans = 0;
        for(int i = 0; i < 2; ++i){
            str += s[i];
            if(us.find(str) != us.end()){
                string st = s.substr(i + 1);
                if(mp.find(st) != mp.end()){
                    ans += mp[st];
                    continue;
                }
                ans += helper(st, us, mp);
            }
        }
        mp[s] = ans;
        return ans;
    }
    int numDecodings(string s) {
        unordered_set<string> us;
        unordered_map<string, int> mp;
        for(int i = 1; i <= 26; ++i){
            us.insert(to_string(i));
        }
        return helper(s, us, mp);
    }
};