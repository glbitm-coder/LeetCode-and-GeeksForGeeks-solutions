class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        int n1 = (int)s.size();
        int n2 = (int)t.size();
        if(n1 != n2)
        {
            return false;
        }
        for(int i  = 0 ; i < n1; ++i)
        {
            mp1[s[i]]++;
        }
        for(int i = 0; i < n2; ++i)
        {
            mp2[t[i]]++;
        }
        for(int i = 0; i < n1; ++ i)
        {
            if(mp2.find(s[i]) == mp2.end())
            {
                return false;
            }
            else
            {
                if(mp2[s[i]] == mp1[s[i]])
                {
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};