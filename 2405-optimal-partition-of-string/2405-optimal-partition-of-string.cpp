class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> mp;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp.insert(s[i]);
            }
            else
            {
                mp.clear();
                mp.insert(s[i]);
                ans += 1;
            }
        }
        return ans + 1;
    }
};