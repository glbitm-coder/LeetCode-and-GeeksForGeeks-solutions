class Solution {
public:
    bool check(unordered_map<char,int> &mp1, unordered_map<char,int> &mp2)
    {
        if(mp1.size() != mp2.size())
            return false;

        for(auto it:mp2){
            if(it.second < mp1[it.first]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mp, mp1;
        pair<int,int> ans;
        ans.first = INT_MAX;
        ans.second = -1;
        for(int i = 0; i < t.size(); ++i){
            mp[t[i]]++;
        }

        for(int i = 0, j = 0; i < s.size(); ++i){

            if(i - j + 1 > ans.first){
                if(j < s.size() && t.find(s[j]) != string::npos){
                    mp1[s[j]]--;
                }
                ++j;
                while(j < s.size() && t.find(s[j]) == string::npos){
                    ++j;  
                }
            }

            if(t.find(s[i]) != string::npos){
                mp1[s[i]]++;
                
                while(check(mp,mp1)){
                    if(i - j + 1 < ans.first){
                        ans.first = i - j + 1;
                        ans.second = j;
                    }
                    if(j < s.size() && t.find(s[j]) != string::npos){
                        mp1[s[j]]--;
                    }
                    
                    ++j;
                    while(j < s.size() && t.find(s[j]) == string::npos){
                        ++j;
                    }
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