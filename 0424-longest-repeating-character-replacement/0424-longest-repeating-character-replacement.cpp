class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int maxCount = 0, ans = 0;
        
        for(int i = 0,j = 0; i < s.size(); ++i){
            
            mp[s[i]]++;
            maxCount = max(maxCount, mp[s[i]]);
        
            while(i - j + 1 - maxCount > k){
                mp[s[j]]--;
                ++j;
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};