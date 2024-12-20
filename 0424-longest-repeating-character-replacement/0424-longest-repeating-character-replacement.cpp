class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int len = 0, maxCount = 0, count = 0, ans = 0;
        
        for(int i = 0,j = 0; i < s.size(); ++i){
            
            mp[s[i]]++;
            len = i - j + 1;
            maxCount = max(maxCount, mp[s[i]]);
        
            while(len - maxCount > k){
                mp[s[j]]--;
                --len;
                ++j;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};