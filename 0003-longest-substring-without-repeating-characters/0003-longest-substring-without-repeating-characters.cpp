class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int ans = 0;
        for(int i = 0,j = 0; i < s.size(); ){
            if(us.find(s[i]) == us.end()){
                us.insert(s[i]);
            }
            else{
                while(s[j] != s[i]){
                    us.erase(s[j]);
                    ++j;
                }
                ++j;
            }
            ans = max(ans, i - j + 1);
            ++i;
        }
        return ans;
    }
};