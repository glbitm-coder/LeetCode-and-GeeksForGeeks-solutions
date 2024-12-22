class Solution {
public:
    
    string minWindow(string s, string t) {

        unordered_map<char,int> mp, mp1;
        pair<int,int> ans;
        
        ans.first = INT_MAX;
        ans.second = -1;
        
        for(int i = 0; i < t.size(); ++i){
            mp[t[i]]++;
        }

        int need = mp.size();
        int have = 0;
        
        for(int i = 0, j = 0; i < s.size(); ++i){

            if(t.find(s[i]) != string::npos){
                mp1[s[i]]++;
                char k = s[i];
                if(mp1[k] == mp[k]){
                    ++have;
                }
                while(have >= need){
                    if(i - j + 1 < ans.first){
                        ans.first = i - j + 1;
                        ans.second = j;
                    }
                    if(j < s.size() && t.find(s[j]) != string::npos){
                        mp1[s[j]]--;
                        if(mp1[s[j]] < mp[s[j]]){
                            --have;
                        }
                        if(mp1[s[j]] == 0) mp1.erase(s[j]);
                    }
                    ++j;
                }
            }
            
        }
        if(ans.second == -1){
            return "";
        }
        string res = s.substr(ans.second, ans.first);
        return res;
    }
};